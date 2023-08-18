/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btnMax;
    QPushButton *btnNormal;
    QPushButton *btnMin;
    QPushButton *btnClose;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(453, 258);
        btnMax = new QPushButton(Widget);
        btnMax->setObjectName("btnMax");
        btnMax->setGeometry(QRect(20, 100, 91, 31));
        btnNormal = new QPushButton(Widget);
        btnNormal->setObjectName("btnNormal");
        btnNormal->setGeometry(QRect(130, 100, 91, 31));
        btnMin = new QPushButton(Widget);
        btnMin->setObjectName("btnMin");
        btnMin->setGeometry(QRect(240, 100, 91, 31));
        btnClose = new QPushButton(Widget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(350, 100, 91, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\344\277\241\345\217\267\344\270\216\346\247\275\347\232\204\347\256\200\345\215\225\344\275\277\347\224\250", nullptr));
        btnMax->setText(QCoreApplication::translate("Widget", "btnMax", nullptr));
        btnNormal->setText(QCoreApplication::translate("Widget", "btnNormal", nullptr));
        btnMin->setText(QCoreApplication::translate("Widget", "btnMin", nullptr));
        btnClose->setText(QCoreApplication::translate("Widget", "btnClose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
