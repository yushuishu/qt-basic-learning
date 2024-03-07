#include "propagate_widget.h"


#include <QVBoxLayout>
#include <QEvent>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:35
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：总结：事件的传递流程
 * <p></p>
 */

PropagateWidget::PropagateWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 1. 添加一个自定义的标签 LabelX
    lbl = new PropagateLabel(this);
    lbl->setText("");
    lbl->setFrameShape(QFrame::Box);
    lbl->setFixedHeight(50);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setStyleSheet("background-color: red;color: white;font-size: 25px");
    verticalLayout->addWidget(lbl);

    lbl->installEventFilter(this);
}

void PropagateWidget::mousePressEvent(QMouseEvent *event) {
    qDebug() << "PropagateWidget::mousePressEvent";
}

bool PropagateWidget::eventFilter(QObject *watched, QEvent *event) {
    if (watched == lbl && event->type() == QEvent::MouseButtonPress) {
        qDebug() << "PropagateWidget::eventFilter";
    }
    return QWidget::eventFilter(watched, event);
}
