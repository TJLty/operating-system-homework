#include "memindex.h"
#include "ui_memindex.h"
#include "memmanage.h"
#include <iostream>
memIndex::memIndex(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::memIndex)
{
    ui->setupUi(this);
    elm=nullptr;
}

memIndex::~memIndex()
{
    delete ui;
    if(elm)
        delete elm;
}

void memIndex::on_pushButton_clicked()
{
    if(elm)
        delete elm;
    elm=new memManage(1);
    elm->show();
}


void memIndex::on_pushButton_2_clicked()
{
    if(elm)
        delete elm;
    elm=new memManage(2);
    elm->show();
}

