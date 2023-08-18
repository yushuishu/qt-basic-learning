#include "widget.h"

#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-18 12:47
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：信号和槽（标准信号槽 和 自定义信号槽）
 * <p></p>
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
