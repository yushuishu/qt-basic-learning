#include "enter_leave_widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QEvent>

#include <labelx.h>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:16
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：鼠标进入/离开
 * <p></p>
 */

EnterLeaveWidget::EnterLeaveWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 使用自定义的标签控件LabelX
    LabelX *lblx = new LabelX(this);
    lblx->setText("鼠标进入/离开");
    lblx->setFrameShape(QFrame::Box);
    lblx->setFixedHeight(50);
    lblx->setAlignment(Qt::AlignCenter);
    lblx->setStyleSheet("background-color: blue;color: white;font-size: 25px");
    verticalLayout->addWidget(lblx);

    // 2. 添加一个标准的QLabel
    lbl = new QLabel(this);
    lbl->setText("标准的QLabel");
    lbl->setFrameShape(QFrame::Box);
    lbl->setFixedHeight(50);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setStyleSheet("background-color: red;color: white;font-size: 25px");

    // 安装事件过滤器
    verticalLayout->addWidget(lbl);
    lbl->installEventFilter(this);
}

static int cnt = 1;

bool EnterLeaveWidget::eventFilter(QObject *watched, QEvent *event) {
    if (watched == lbl) {
        if (event->type() == QEvent::Enter) {
            lbl->setText(QString("enterEvent: %1").arg(cnt++));
        } else if (event->type() == QEvent::Leave) {
            lbl->setText(QString("leaveEvent: %1").arg(cnt++));
        }
    }
    return QWidget::eventFilter(watched, event);
}
