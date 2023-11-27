#include "widget.h"

#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-19 21:02
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：信号和槽要建立连接，本质上是通过 `connect` 函数来连接实现的。
 * 但是从写法或者操作上来说，有多种方式，以下总结了 5 种方式：
 *      SIGNAL/SLOT（Qt4）
 *      函数地址（Qt5）
 *      UI 设计师界面 - 转到槽
 *      UI 设计师界面 - 信号槽编辑器
 *      lambda 表达式
 * <p></p>
 */


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
