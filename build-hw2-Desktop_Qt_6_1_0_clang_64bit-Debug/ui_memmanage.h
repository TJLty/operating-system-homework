/********************************************************************************
** Form generated from reading UI file 'memmanage.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMMANAGE_H
#define UI_MEMMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memManage
{
public:
    QTextBrowser *memBrowser;
    QGroupBox *groupBox;
    QSpinBox *mallocID;
    QSpinBox *mallocSize;
    QLabel *label;
    QLabel *label_2;
    QPushButton *mallocButton;
    QLabel *label_3;
    QGroupBox *groupBox_2;
    QSpinBox *freeID;
    QLabel *label_4;
    QPushButton *freeButton;
    QPushButton *viewButton;
    QPushButton *exitButton;

    void setupUi(QWidget *memManage)
    {
        if (memManage->objectName().isEmpty())
            memManage->setObjectName(QString::fromUtf8("memManage"));
        memManage->resize(640, 710);
        memBrowser = new QTextBrowser(memManage);
        memBrowser->setObjectName(QString::fromUtf8("memBrowser"));
        memBrowser->setGeometry(QRect(20, 20, 600, 500));
        memBrowser->setAutoFillBackground(false);
        memBrowser->setStyleSheet(QString::fromUtf8("background-color:black;color:white"));
        groupBox = new QGroupBox(memManage);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 550, 380, 61));
        mallocID = new QSpinBox(groupBox);
        mallocID->setObjectName(QString::fromUtf8("mallocID"));
        mallocID->setGeometry(QRect(120, 0, 60, 30));
        mallocID->setMaximum(10000);
        mallocSize = new QSpinBox(groupBox);
        mallocSize->setObjectName(QString::fromUtf8("mallocSize"));
        mallocSize->setGeometry(QRect(120, 30, 60, 30));
        mallocSize->setMaximum(10000);
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 80, 30));
        label->setTextFormat(Qt::PlainText);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 120, 30));
        label_2->setTextFormat(Qt::PlainText);
        mallocButton = new QPushButton(groupBox);
        mallocButton->setObjectName(QString::fromUtf8("mallocButton"));
        mallocButton->setGeometry(QRect(200, 0, 180, 60));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 30, 30, 30));
        label_3->setTextFormat(Qt::PlainText);
        groupBox_2 = new QGroupBox(memManage);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 640, 380, 60));
        freeID = new QSpinBox(groupBox_2);
        freeID->setObjectName(QString::fromUtf8("freeID"));
        freeID->setGeometry(QRect(120, 0, 60, 30));
        freeID->setMaximum(10000);
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(0, 0, 50, 31));
        label_4->setTextFormat(Qt::PlainText);
        freeButton = new QPushButton(groupBox_2);
        freeButton->setObjectName(QString::fromUtf8("freeButton"));
        freeButton->setGeometry(QRect(200, 0, 180, 60));
        viewButton = new QPushButton(memManage);
        viewButton->setObjectName(QString::fromUtf8("viewButton"));
        viewButton->setGeometry(QRect(440, 550, 180, 60));
        exitButton = new QPushButton(memManage);
        exitButton->setObjectName(QString::fromUtf8("exitButton"));
        exitButton->setGeometry(QRect(440, 640, 180, 60));

        retranslateUi(memManage);

        QMetaObject::connectSlotsByName(memManage);
    } // setupUi

    void retranslateUi(QWidget *memManage)
    {
        memManage->setWindowTitle(QCoreApplication::translate("memManage", "1950698 \351\231\206\345\244\251\345\256\207", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("memManage", "\344\275\234\344\270\232(\345\210\206\345\214\272\345\217\267)", nullptr));
        label_2->setText(QCoreApplication::translate("memManage", "\351\234\200\350\246\201\345\210\206\351\205\215\347\232\204\344\270\273\345\255\230\345\244\247\345\260\217", nullptr));
        mallocButton->setText(QCoreApplication::translate("memManage", "\345\210\206\351\205\215\345\206\205\345\255\230", nullptr));
        label_3->setText(QCoreApplication::translate("memManage", "KB", nullptr));
        groupBox_2->setTitle(QString());
        label_4->setText(QCoreApplication::translate("memManage", "\345\210\206\345\214\272\345\217\267", nullptr));
        freeButton->setText(QCoreApplication::translate("memManage", "\345\210\240\351\231\244\345\206\205\345\255\230", nullptr));
        viewButton->setText(QCoreApplication::translate("memManage", "\346\237\245\347\234\213\345\210\206\351\205\215", nullptr));
        exitButton->setText(QCoreApplication::translate("memManage", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class memManage: public Ui_memManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMMANAGE_H
