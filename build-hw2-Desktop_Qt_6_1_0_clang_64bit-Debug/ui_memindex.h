/********************************************************************************
** Form generated from reading UI file 'memindex.ui'
**
** Created by: Qt User Interface Compiler version 6.1.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMINDEX_H
#define UI_MEMINDEX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_memIndex
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *memIndex)
    {
        if (memIndex->objectName().isEmpty())
            memIndex->setObjectName(QString::fromUtf8("memIndex"));
        memIndex->resize(220, 230);
        pushButton = new QPushButton(memIndex);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 40, 180, 60));
        pushButton_2 = new QPushButton(memIndex);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 130, 180, 60));

        retranslateUi(memIndex);

        QMetaObject::connectSlotsByName(memIndex);
    } // setupUi

    void retranslateUi(QWidget *memIndex)
    {
        memIndex->setWindowTitle(QCoreApplication::translate("memIndex", "\351\246\226\351\241\265", nullptr));
        pushButton->setText(QCoreApplication::translate("memIndex", "\351\246\226\346\254\241\351\200\202\345\272\224\347\256\227\346\263\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("memIndex", "\346\234\200\344\275\263\351\200\202\345\272\224\347\256\227\346\263\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class memIndex: public Ui_memIndex {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMINDEX_H
