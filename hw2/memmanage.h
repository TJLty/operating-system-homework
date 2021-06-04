#ifndef MEMMANAGE_H
#define MEMMANAGE_H

#include <QWidget>
#include <QPushButton>
#include <QTextBrowser>
#include <QSpinBox>
QT_BEGIN_NAMESPACE
namespace Ui { class memManage; }
QT_END_NAMESPACE
#define Free 0 //空闲状态
#define Busy 1 //已用状态
#define OK 1    //完成
#define ERROR 0 //出错
#define MAX_length 640 //最大内存空间为640KB
typedef int Status;
class memManage : public QWidget
{
    Q_OBJECT

public:
    memManage(int OPT,QWidget *parent = nullptr);
    ~memManage();

private:
    Ui::memManage *ui;

public:
    int opt;
    QPushButton *mallocButton;
    QPushButton *freeButton;
    QPushButton *exitButton;
    QPushButton *viewButton;
    QTextBrowser *memBrowser;
    QSpinBox *mallocID;
    QSpinBox *mallocSize;
    QSpinBox *freeID;
    typedef struct freearea//定义一个空闲区说明表结构
    {
        int ID;   //分区号
        long size;   //分区大小
        long address; //分区地址
        int state;   //状态
    }ElemType;
    //----------  线性表的双向链表存储结构  ------------
    typedef struct DuLNode //double linked list
    {
        ElemType data;
        struct DuLNode *prior; //前趋指针
        struct DuLNode *next;  //后继指针
    }DuLNode,*DuLinkList;

    DuLinkList block_first; //头结点
    DuLinkList block_last;  //尾结点
private slots:
    Status memAlloc();//内存分配
    Status memFree(); //内存回收
    void view();//查看分配

public:
    Status First_fit(int,int);//首次适应算法
    Status Best_fit(int,int); //最佳适应算法
    Status Initblock();//开创空间表

};
#endif // MEMMANAGE_H
