#include "widget.h"
#include "ui_widget.h"
#include "commander.h"
#include "soldier.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-18 13:09
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

    // 设置按钮文本
    ui->btnMax->setText("最大化显示");
    ui->btnNormal->setText("正常显示");
    ui->btnMin->setText("最小化");
    ui->btnClose->setText("关闭窗口");

    // Qt标准信号槽
    // connect() 连接信号和槽
    // connect(sender, signal, receiver, slot)
    //      sender: 发出信号的对象，比如 QpushButton 按钮
    //      signal: 发出的信号，比如 clicked() 点击操作
    //      receiver: 接收信号的对象，比如 QWidget 窗口
    //      slot: 接收信号之后，调用的函数
    connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));
    connect(ui->btnNormal, SIGNAL(clicked()), this, SLOT(showNormal()));
    connect(ui->btnMin, SIGNAL(clicked()), this, SLOT(showMinimized()));
    connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));

    // 自定义信号槽
    //  1、创建两个实例
    Commander commander;
    Soldier soldier;
    //  2、建立信号和槽的连接
    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(go(Qstring)), &soldier, SLOT(fight(Qstring)));
    //  3、发送信号
    commander.go();
    commander.go("freedom");

}

Widget::~Widget()
{
    delete ui;
}

