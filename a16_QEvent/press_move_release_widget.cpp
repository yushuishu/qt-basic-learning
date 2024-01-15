#include "press_move_release_widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include "labelx.h"
#include <QEvent>
#include <QMouseEvent>
#include <QDebug>


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:30
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：鼠标按下/移动/释放
 * <p></p>
 */

PressMoveReleaseWidget::PressMoveReleaseWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 自定义的LabelX
    LabelX *lblx = new LabelX(this);
    lblx->setText("鼠标按下/移动/释放");
    lblx->setFrameShape(QFrame::Box);
    lblx->setFixedHeight(50);
    lblx->setAlignment(Qt::AlignCenter);
    lblx->setStyleSheet("background-color: blue;color: white;font-size: 25px");
    verticalLayout->addWidget(lblx);

    // 标准的QLabel
    widget = new QWidget(this);
    lbl = new QLabel(widget);
    lbl->setText("");
    lbl->setFrameShape(QFrame::Box);
    lbl->setFixedSize(100, 100);
    lbl->setStyleSheet("background-color: red");
    verticalLayout->addWidget(widget);
    // 安装事件过滤器
    lbl->installEventFilter(this);
}

bool PressMoveReleaseWidget::eventFilter(QObject *watched, QEvent *event) {
    if (watched != lbl) {
        return QWidget::eventFilter(watched, event);
    }

    if (event->type() == QEvent::MouseButtonPress) {
        qDebug() << "MouseButtonPress";
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        localGlobalPosition = mouseEvent->globalPosition();
        wndPos = lbl->pos();
        qDebug() << wndPos;
    } else if (event->type() == QEvent::MouseMove) {
        qDebug() << "MouseMove";
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        QPointF dstPos = wndPos + (mouseEvent->globalPosition() - localGlobalPosition);
        lbl->move(dstPos.x(), dstPos.y());
        // 超出了最左边
        if (lbl->pos().x() < 0) {
            qDebug() << "超出了最左边，x：" << lbl->pos().x() << "，y：" << dstPos.y();
            lbl->move(0, dstPos.y());
        }
        // 超出了最右边
        if (lbl->pos().x() > widget->width() - lbl->width()) {
            qDebug() << "超出了最右边，x：" << lbl->pos().x() << "，y：" << dstPos.y();
            lbl->move(widget->width() - lbl->width(), dstPos.y());
        }
        // 超出了最上边
        if (lbl->pos().y() < 0) {
            qDebug() << "超出了最上边，x：" << lbl->pos().x() << "，y：" << dstPos.y();
            lbl->move(dstPos.x(), 0);
        }
        // 超出了最下边
        if (lbl->pos().y() > widget->height() - lbl->height()) {
            qDebug() << "超出了最下边，x：" << lbl->pos().x() << "，y：" << dstPos.y();
            lbl->move(dstPos.x(), widget->height() - lbl->height());
        }
    } else if (event->type() == QEvent::MouseButtonRelease) {
        qDebug() << "MouseButtonRelease";
    }
    return false;
}
