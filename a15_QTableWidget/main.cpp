#include "widget.h"

#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-12 08:49
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
