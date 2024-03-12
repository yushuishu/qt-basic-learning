#include "framelesswidget.h"

#include <QApplication>



/**
 * @Author ：谁书-ss
 * @Date ：2024-03-11 11:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    FramelessWidget w;
    w.show();
    return a.exec();
}
