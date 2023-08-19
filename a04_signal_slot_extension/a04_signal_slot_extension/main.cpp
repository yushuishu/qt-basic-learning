#include "widget.h"

#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-19 21:47
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：信号和槽的扩展知识
 * 1、如何连接重载的信号和槽
 *  在信号和槽存在重载时，Qt4 和 Qt5 的写法是有区别的：
 *  Qt4 方式: 可以在 SIGNAL/SLOT 中指定函数参数类型，因此写法比较简单。
 *  Qt5 方式: 指定信号和槽时，只能指定函数名，无法向 Qt4 那样指定函数参数类型，需要单独定义函数指针，写法上稍显麻烦。
 *
 * 2、一个信号连接多个槽
 *  connect(sender, SIGNAL(signal), receiver1, SLOT(fun1()));
 *  connect(sender, SIGNAL(signal), receiver2, SLOT(fun2()));
 *  这样，当 signal 这个信号发出时，它连接的 2 个槽函数 fun1，fun2 都会被执行，并且：
 *  Qt4：信号发射时，与之相连接的槽函数的执行顺序是随机的。
 *  Qt5+: 信号发射时，这些槽函数的执行顺序与建立连接的顺序相同。
 *
 * 3、多个信号连接一个槽
 *  connect(sender, SIGNAL(signal1), receiver, SLOT(fun()));
 *  connect(sender, SIGNAL(signal2), receiver, SLOT(fun()));
 *
 * 4、信号连接信号
 *  信号不仅可以连接槽，还可以和连接信号，如：connect(obj1, SIGNAL(signal1), obj2, SIGNAL(signal2));
 *  这样，当 obj1 发送 signal1 信号时，就会触发 obj2 发送 signal2 信号。
 *
 * 5、断开连接 - disconnect
 *  用于断开信号和槽之间已经建立的连接。disconnect 函数并不常用，因为当一个对象 delete 之后， Qt 自动取消所有连接到这个对象上面的槽。
 * <p></p>
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
