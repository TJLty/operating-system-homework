#include "memmanage.h"
#include "ui_memmanage.h"
#include <QMessageBox>
#include <QObject>
#include <iostream>
memManage::memManage(int OPT,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::memManage)
{
    ui->setupUi(this);
    opt=OPT;
    mallocButton=ui->mallocButton;
    freeButton=ui->freeButton;
    exitButton=ui->exitButton;
    viewButton=ui->viewButton;
    memBrowser=ui->memBrowser;
    mallocID=ui->mallocID;
    mallocSize=ui->mallocSize;
    freeID=ui->freeID;
    connect(exitButton,SIGNAL(clicked()),this,SLOT(close()));
    connect(mallocButton,SIGNAL(clicked()),this,SLOT(memAlloc()));
    connect(viewButton,SIGNAL(clicked()),this,SLOT(view()));
    connect(freeButton,SIGNAL(clicked()),this,SLOT(memFree()));
    Initblock();
}

memManage::~memManage()
{
    delete ui;
    DuLNode *p=block_first;
    while(p)
    {
        DuLNode *temp=p;
        p=p->next;
        delete temp;
    }
}
Status memManage::Initblock()//开创带头结点的内存空间链表
{
    block_first=new DuLNode;
    block_last =new DuLNode;
    block_first->prior= nullptr;
    block_first->next=block_last;
    block_last->prior=block_first;
    block_last->next= nullptr;
    block_last->data.address=0;
    block_last->data.size=MAX_length;
    block_last->data.ID=0;
    block_last->data.state=Free;
    return OK;
}
//------------------ 首次适应算法 -----------------------
Status memManage::First_fit(int ID,int request)//传入作业名及申请量
{
    //为申请作业开辟新空间且初始化
    auto temp=new DuLNode;
    temp->data.ID=ID;
    temp->data.size=request;
    temp->data.state=Busy;

    DuLNode *p=block_first->next;
    while(p)
    {
        if(p->data.state==Free && p->data.size==request)
        {//有大小恰好合适的空闲块
            p->data.state=Busy;
            p->data.ID=ID;
            delete temp;
            return OK;
        }
        if(p->data.state==Free && p->data.size>request)
        {//有空闲块能满足需求且有剩余"
            temp->prior=p->prior;
            temp->next=p;
            temp->data.address=p->data.address;
            p->prior->next=temp;
            p->prior=temp;
            p->data.address=temp->data.address+temp->data.size;
            p->data.size-=request;
            return OK;
        }
        p=p->next;
    }
    delete temp;
    return ERROR;
}
//--------------------  最佳适应算法  ------------------------
Status memManage::Best_fit(int ID,int request)//传入作业名及申请量
{
    int ch; //记录最小剩余空间
    auto temp=new DuLNode;
    temp->data.ID=ID;
    temp->data.size=request;
    temp->data.state=Busy;
    DuLNode *p=block_first->next;
    DuLNode *q= nullptr; //记录最佳插入位置
    while(p) //初始化最小空间和最佳位置
    {
        if(p->data.state==Free &&
            (p->data.size>request || p->data.size==request) )
        {
            q=p;
            ch=(int)p->data.size-request;
            break;
        }
        p=p->next;
    }
    while(p)
    {
        if(p->data.state==Free && p->data.size==request)
        {//空闲块大小恰好合适
            p->data.ID=ID;
            p->data.state=Busy;
            delete temp;
            return OK;
        }
        if(p->data.state==Free && p->data.size>request)
        {//空闲块大于分配需求
            if(p->data.size-request<ch)//剩余空间比初值还小
            {
                ch=(int)p->data.size-request;//更新剩余最小值
                q=p;//更新最佳位置指向
            }
        }
        p=p->next;
    }
    if(q == nullptr){delete temp; return ERROR;}//没有找到空闲块
    else
    {//找到了最佳位置并实现分配
        temp->prior=q->prior;
        temp->next=q;
        temp->data.address=q->data.address;
        q->prior->next=temp;
        q->prior=temp;
        q->data.address+=request;
        q->data.size=ch;
        return OK;
    }
}

//---------------  显示主存分配情况 ------------------
void memManage::view()
{
    QString info;
    memBrowser->clear();
    info+="+++++++++++++++++++++++++++++++++\n";
    info+="+++++++        主 存 分 配 情 况        +++++++\n";
    info+="+++++++++++++++++++++++++++++++++\n";
    /*
    memBrowser->append("+++++++++++++++++++++++++++++++++++++++\n");
    memBrowser->append("+++        主 存 分 配 情 况        +++\n");
    memBrowser->append("+++++++++++++++++++++++++++++++++++++++\n");
    */
    DuLNode *p=block_first->next;
    while(p)
    {
        info+="分 区 号：";
        if(p->data.ID==Free) info+=("Free\n");
        else info+=(QString::number(p->data.ID)+"\n");
        info+=("起始地址："+QString::number(p->data.address)+"\n");
        info+=("分区大小："+QString::number(p->data.size)+" KB\n");
        info+=("状    态：");
        if(p->data.state==Free) info+=("空  闲\n");
        else info+=("已分配\n");
        info+=("——————————————\n");
        p=p->next;
    }
    memBrowser->append(info);
}
//----------------------- 分 配 主 存 -------------------------
Status memManage::memAlloc()
{
    int ID,request;
    ID=mallocID->value();
    request=mallocSize->value();
    if(request<0 ||request==0)
    {
        QMessageBox::information(NULL,"提示","分配大小不合适，请重试！");
        return ERROR;
    }

    if(opt==2) //选择最佳适应算法
    {
        if(Best_fit(ID,request)==OK)
            QMessageBox::information(NULL,"提示","分配成功！");
        else
            QMessageBox::information(NULL,"提示","内存不足，分配失败！");
        view();
        return OK;
    }
    else //默认首次适应算法
    {
        if(First_fit(ID,request)==OK)
            QMessageBox::information(NULL,"提示","分配成功！");
        else
            QMessageBox::information(NULL,"提示","内存不足，分配失败！");
        view();
        return OK;
    }
}

//-----------------------   主 存 回 收   --------------------
Status memManage::memFree()
{
    int ID=freeID->value();
    DuLNode *p=block_first->next;
    while(p)
    {
        if(p->data.ID==ID)
        {
            p->data.state=Free;
            p->data.ID=Free;
            if(p->next!=nullptr&&p->next->data.state==Free)//与后面的空闲块相连
            {
                DuLNode *temp=p->next;
                p->data.size+=p->next->data.size;
                if(p->next->next!=nullptr)
                    p->next->next->prior=p;
                p->next=p->next->next;
                if(temp==block_last)
                    block_last=p;
                delete temp;
            }
            if(p->prior!=block_first&&p->prior->data.state==Free)//与前面的空闲块相连
            {
                p->prior->data.size+=p->data.size;
                p->prior->next=p->next;
                if(p->next!=nullptr)
                    p->next->prior=p->prior;
                delete p;
            }
            //std::cout<<(int64_t)p->prior<<std::endl;
            break;
        }
        p=p->next;
    }
    QMessageBox::information(NULL,"提示","已回收！");
    view();
    return OK;
}

