/********************************************************************************
** Form generated from reading UI file 'index.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INDEX_H
#define UI_INDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_index
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *index)
    {
        if (index->objectName().isEmpty())
            index->setObjectName(QString::fromUtf8("index"));
        index->resize(230, 173);
        pushButton = new QPushButton(index);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 180, 60));
        pushButton_2 = new QPushButton(index);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 90, 180, 60));

        retranslateUi(index);

        QMetaObject::connectSlotsByName(index);
    } // setupUi

    void retranslateUi(QWidget *index)
    {
        index->setWindowTitle(QCoreApplication::translate("index", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("index", "\351\246\226\346\254\241\351\200\202\345\272\224\347\256\227\346\263\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("index", "\351\200\211\346\213\251\346\234\200\344\275\263\351\200\202\345\272\224\347\256\227\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class index: public Ui_index {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INDEX_H
