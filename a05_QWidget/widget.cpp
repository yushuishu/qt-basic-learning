#include "widget.h"
#include "ui_widget.h"
#include "subwidget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-09-16 15:24
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 未指定父窗口 那么这个窗口就是独立的窗口，需要调用show方法来显示
    // 如果指定了父窗口，那么就不需要调用show方法了，因为父窗口显示时，会将其子窗口一起显示出来。
    SubWidget* subWidget = new SubWidget(this);
    subWidget->setWindowTitle("SubWidget");

    // 设置窗体的几何信息
    QRect qRect = subWidget->geometry();

}

Widget::~Widget()
{
    delete ui;
}

