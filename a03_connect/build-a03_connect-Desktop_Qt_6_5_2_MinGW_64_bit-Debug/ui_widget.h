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
    QPushButton *btnSetTitle;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(473, 325);
        btnMax = new QPushButton(Widget);
        btnMax->setObjectName("btnMax");
        btnMax->setGeometry(QRect(60, 20, 351, 41));
        QFont font;
        font.setPointSize(14);
        btnMax->setFont(font);
        btnNormal = new QPushButton(Widget);
        btnNormal->setObjectName("btnNormal");
        btnNormal->setGeometry(QRect(60, 80, 351, 41));
        btnNormal->setFont(font);
        btnMin = new QPushButton(Widget);
        btnMin->setObjectName("btnMin");
        btnMin->setGeometry(QRect(60, 140, 351, 41));
        btnMin->setFont(font);
        btnClose = new QPushButton(Widget);
        btnClose->setObjectName("btnClose");
        btnClose->setGeometry(QRect(60, 200, 351, 41));
        btnClose->setFont(font);
        btnSetTitle = new QPushButton(Widget);
        btnSetTitle->setObjectName("btnSetTitle");
        btnSetTitle->setGeometry(QRect(60, 260, 351, 41));
        btnSetTitle->setFont(font);

        retranslateUi(Widget);
        QObject::connect(btnClose, &QPushButton::clicked, Widget, qOverload<>(&QWidget::close));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnMax->setText(QCoreApplication::translate("Widget", "\346\234\200\345\244\247\345\214\226\346\230\276\347\244\272\357\274\2101\343\200\201SIGNAL/SLOT\357\274\211", nullptr));
        btnNormal->setText(QCoreApplication::translate("Widget", "\346\255\243\345\270\270\346\230\276\347\244\272\357\274\2102\343\200\201\345\207\275\346\225\260\345\234\260\345\235\200\357\274\211", nullptr));
        btnMin->setText(QCoreApplication::translate("Widget", "\346\234\200\345\260\217\345\214\226\346\230\276\347\244\272\357\274\2103\343\200\201ui --->\346\247\275\357\274\211", nullptr));
        btnClose->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255\347\252\227\345\217\243\357\274\2104\343\200\201ui ---> \344\277\241\345\217\267\346\247\275\347\274\226\350\276\221\345\231\250\357\274\211", nullptr));
        btnSetTitle->setText(QCoreApplication::translate("Widget", "\344\277\256\346\224\271\347\252\227\345\217\243\346\240\207\351\242\230\357\274\2105\343\200\201lambda\350\241\250\350\276\276\345\274\217\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
