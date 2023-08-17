#include "widget.h"
#include "ui_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-17 22:52
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：窗口类
 * <p></p>
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) // 在初始化列表中，对ui指针进行初始化赋值
{
    // 并将当前窗口，也就是this指针，设置到ui对象中
    // 只有这样，我们在ui界面中拖拽的控件才会在随MyWindow显示出来。
    ui->setupUi(this);

    // 之后就可以对拖拽的那些控件进行各种操作了，比如下面设置按钮显示的文字。
    //      前提是双击wirdget.ui文件，拖动两个push_Button控件到窗口，编辑名字等信息
    ui->btn_start->setText("启动");
    ui->btn_stop->setText("停止");
}

Widget::~Widget()
{
    // 既然在构造函数中 new 了ui对象，在析构中要delete销毁
    delete ui;
}

