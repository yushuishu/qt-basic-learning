#include "propagatelabel.h"

#include <QDebug>
#include <QMouseEvent>

/**
 * @Author ：谁书-ss
 * @Date ：2024-03-06 16:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

PropagateLabel::PropagateLabel(QWidget *parent)
    : QLabel{parent}
{}

void PropagateLabel::mousePressEvent(QMouseEvent *event) {
    qDebug() << "PropagateLabel::mousePressEvent";

    // 接受事件（事件到此为止，不再传递给其父控件）
    // 方法一：
    // event->accept();

    // 方法二：什么都不用写。因为传递过来的 event 其 accept 标志位默认为 true，可打印验证
    // qDebug() << event->isAccepted();

    // 忽略事件（事件继续传递给父控件）
    event->ignore();
}

bool PropagateLabel::event(QEvent *e) {
    if ( e->type() == QEvent::MouseButtonPress ) {
        qDebug() << "PropagateLabel::event";
        //return true;
        return false;
    }
    // 调用父类的event()函数
    return QLabel::event(e);
}
