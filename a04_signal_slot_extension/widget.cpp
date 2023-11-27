#include "widget.h"
#include "ui_widget.h"

#include "commander.h"
#include "soldier.h"

/**
 * @Author ：谁书-ss
 * @Date ：2023-08-19 21:47
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

    // 1、Qt4信号槽的连接：SIGNAL/SLOT【重载的信号和槽】
    std::cout << "1、Qt4信号槽的连接：SIGNAL/SLOT【重载的信号和槽】" << std::endl;
    Commander commander;
    Soldier soldier;
    connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
    connect(&commander, SIGNAL(go(QString)), &soldier, SLOT(fight(QString)));
    emit commander.go();
    emit commander.go("freedom");



    // 2、Qt5信号槽的连接：函数地址【重载的信号和槽】
    std::cout << "2、Qt5信号槽的连接：函数地址【重载的信号和槽】" << std::endl;
    Commander commander2;
    Soldier soldier2;
    // 没有同名的信号和槽时，可以直接这样写。因为不存在二义性
    //connect(&commander2, &Commander::go, &soldier2, &Soldier::fight);

    // 有同名的信号和槽时，需要向下面这样定义函数指针。因为存在二义性
    // 【无参】编译器自动推断：将无参的信号go和无参的槽，赋值给函数指针（ctrl+鼠标点击可以智能跳转过去）
    void (Commander::*pGo)() = &Commander::go;
    void (Soldier::*pFight)() = &Soldier::fight;
    connect(&commander2, pGo, &soldier2, pFight);
    // 【有参】编译器自动推断：将有参的信号go和有参的槽，赋值给函数指针（ctrl+鼠标点击可以智能跳转过去）
    void (Commander::*pGoForFreedom)(QString) = &Commander::go;
    void (Soldier::*pFightForFreedom)(QString) = &Soldier::fight;
    connect(&commander2, pGoForFreedom, &soldier2, pFightForFreedom);

    emit commander2.go();
    emit commander2.go("freedom");



    // 3、一个信号可以连接多个槽函数
    std::cout << "3、一个信号可以连接多个槽函数" << std::endl;
    //  connect(sender, SIGNAL(signal), receiver1, SLOT(fun1()));
    //  connect(sender, SIGNAL(signal), receiver2, SLOT(fun2()));
    //这样，当 signal 这个信号发出时，它连接的 2 个槽函数 fun1，fun2 都会被执行，并且：
    //  Qt4 信号发射时，与之相连接的槽函数的执行顺序是随机的。
    //  Qt5 信号发射时，这些槽函数的执行顺序与建立连接的顺序相同。
    Commander commander3;
    Soldier soldier3_1;
    Soldier soldier3_2;
    // 士兵1很勇敢，收到冲锋的信号后，开始战斗
    connect(&commander3, SIGNAL(go()), &soldier3_1, SLOT(fight()));
    // 士兵2很怕死，收到冲锋的信号后，开始逃跑
    connect(&commander3, SIGNAL(go()), &soldier3_2, SLOT(escape()));

    emit commander3.go();



    // 4、多个信号连接一个槽
    std::cout << "4、多个信号连接一个槽" << std::endl;
    // 如下
    // connect(sender, SIGNAL(signal1), receiver, SLOT(fun()));
    // connect(sender, SIGNAL(signal2), receiver, SLOT(fun()));
    // 这样，当 signal1 和 singnal2 这 2 个信号发出时，都会执行槽函数 fun
    // 首先在 Commander 类中新添加一个 move 的信号
    Commander commander4;
    Soldier soldier4;
    // 当 commander 发射 go 信号和 move 信号时，都会执行士兵的 fight 槽函数，开始战斗
    connect(&commander4, SIGNAL(go()), &soldier4, SLOT(fight()));
    connect(&commander4, SIGNAL(move()), &soldier4, SLOT(fight()));
    emit commander4.go();
    emit commander4.move();



    // 5、信号连接信号
    std::cout << "5、信号连接信号" << std::endl;
    // 信号不仅可以连接槽， 还可以和连接信号，如下：
    // connect(obj1, SIGNAL(signal1), obj2, SIGNAL(signal2));
    // 这样，当 obj1 发送 signal1 信号时，就会触发 obj2 发送 signal2 信号。

    // 在 widget.h 中添加 commander 和 soldier 两个指针类型的成员变量

    // 成员变量初始化
    commander5 = new Commander();
    soldier5 = new Soldier();
    // 然后，信号连接信号 + 信号连接槽
    connect(ui->btnAction, &QPushButton::clicked, commander5, &Commander::move);
    connect(commander5, &Commander::move, soldier5, &Soldier::escape);
    // 此时，点击按钮，按钮会发射 clicked 信号，接着 commander5 发射 move 信号，
    // move 信号的发射，会去执行 soldier5 的 escape 槽函数
    // 注意：
    //      此时的 commander 和 soldier 要定义为类的成员变量。
    //      因为如果把 commander 和 soldier 定义为局部变量，Widget 构造执行完毕后，这两个变量就已经释放了



    // 6、断开连接 - disconnect
    std::cout << "6、断开连接 - disconnect" << std::endl;
    // disconnect 用于断开信号和槽之间已经建立的连接。
    // 种情况并不常用，因为当一个对象 delete 之后， Qt 自动取消所有连接到这个对象上面的槽。
    Commander commander6;
    Soldier soldier6;
    connect(&commander6, SIGNAL(go()), &soldier6, SLOT(fight()));
    connect(&commander6, SIGNAL(go(QString)), &soldier6, SLOT(fight(QString)));
    emit commander6.go();
    // 断开所有连接到 commander 信号上的槽函数
    commander6.disconnect();
    // 对应的槽函数不会执行
    emit commander6.go("freedom 666");


}

Widget::~Widget()
{
    delete ui;
}

