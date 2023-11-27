#include "widget.h"

#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-17 22:52
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：qt入门程序
 * <p></p>
 * main.cpp 文件是 Qt 程序的入口文件，其中的 main 函数是入口函数
 */

int main(int argc, char *argv[])
{
    // 1. QApplication 是 Qt 框架提供的应用程序类
    // 作用：负责 Qt 中事件的处理，比如鼠标的单击事件，键盘的输入事件等
    QApplication a(argc, argv);
    // 2. 创建自己的窗口对象，并调用其 show 方法，将窗口显示出来
    Widget w;
    w.show();
    // 3. 调用 QApplication 类的 exec 方法，应用程序就阻塞在这里，并不会退出，
    // 而是进入到事件循环的处理, 直到退出程序(比如点击了窗体右上角的关闭按钮)
    return a.exec();
}
