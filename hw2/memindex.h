#ifndef MEMINDEX_H
#define MEMINDEX_H

#include <QWidget>
#include "memmanage.h"
namespace Ui {
class memIndex;
}

class memIndex : public QWidget
{
    Q_OBJECT

public:
    explicit memIndex(QWidget *parent = nullptr);
    ~memIndex();

private slots:
    void on_pushButton_clicked();//首次适应算法模拟
    void on_pushButton_2_clicked();//最佳适应算法模拟

private:
    Ui::memIndex *ui;
public:
    memManage *elm;

};

#endif // MEMINDEX_H
