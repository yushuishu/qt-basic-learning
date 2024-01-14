#include "labelx.h"

#include<QDebug>
#include <QMouseEvent>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-11 22:18
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

LabelX::LabelX(QWidget *parent)
    : QLabel{parent} {
    // 默认false，设置为ture，也能监听触发鼠标移动事件
    this->setMouseTracking(true);
}

static int cnt = 1;

void LabelX::enterEvent(QEnterEvent *enterEvent) {
    Q_UNUSED(enterEvent)
    //qDebug() << "enterEvent: " << cnt++;
    this->setText(QString("enterEvent: %1").arg(cnt++));
}

void LabelX::leaveEvent(QEvent *event) {
    Q_UNUSED(event)
    //qDebug() << "leaveEvent: " << cnt++;
    this->setText(QString("leaveEvent: %1").arg(cnt++));
}

void LabelX::mousePressEvent(QMouseEvent *qmouseEvent) {

    qDebug() << "mousePressEvent: " << qmouseEvent->button() << qmouseEvent->pos() << qmouseEvent->globalPosition();
    if (qmouseEvent->button() == Qt::LeftButton) {
        qDebug() << "左键按下: " << "x=" << qmouseEvent->position().x() << ", y=" << qmouseEvent->position().y();
    }
    if (qmouseEvent->button() == Qt::RightButton) {
        qDebug() << "右键按下: " << "x=" << qmouseEvent->position().x() << ", y=" << qmouseEvent->position().y();
    }
}

void LabelX::mouseReleaseEvent(QMouseEvent *qmouseEvent) {
    qDebug() << "mouseReleaseEvent: " << qmouseEvent->button() << qmouseEvent->pos() << qmouseEvent->globalPosition();
    if (qmouseEvent->button() == Qt::LeftButton) {
        qDebug() << "左键释放: " << "x=" << qmouseEvent->position().x() << ", y=" << qmouseEvent->position().y();
    }
    if (qmouseEvent->button() == Qt::RightButton) {
        qDebug() << "右键释放: " << "x=" << qmouseEvent->position().x() << ", y=" << qmouseEvent->position().y();
    }
}

void LabelX::mouseMoveEvent(QMouseEvent *qmouseEvent) {
    qDebug() << "mouseReleaseEvent: " << qmouseEvent->buttons() << qmouseEvent->pos() << qmouseEvent->globalPosition();
    if (qmouseEvent->buttons() & Qt::LeftButton) {
        qDebug() << "鼠标左键移动中：x=" << qmouseEvent->position().x() << "， y=" << qmouseEvent->position().y();
    }
}
