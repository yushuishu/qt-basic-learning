#pragma once
/********************************************************************************
** Form generated from reading UI file ''
**
** Created by: Qt User Interface Compiler version 6.5.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *btn_start;
    QPushButton *btn_stop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(800, 600);
        btn_start = new QPushButton(Widget);
        btn_start->setObjectName("btn_start");
        btn_start->setGeometry(QRect(160, 130, 131, 41));
        QFont font;
        font.setPointSize(16);
        btn_start->setFont(font);
        btn_stop = new QPushButton(Widget);
        btn_stop->setObjectName("pushButton_2");
        btn_stop->setGeometry(QRect(320, 130, 131, 41));
        btn_stop->setFont(font);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btn_start->setText(QCoreApplication::translate("Widget", "start", nullptr));
        btn_stop->setText(QCoreApplication::translate("Widget", "stop", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

