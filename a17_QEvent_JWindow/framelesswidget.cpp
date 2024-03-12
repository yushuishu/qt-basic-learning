#include "framelesswidget.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QDebug>
#include <QMouseEvent>

/**
 * @Author ：谁书-ss
 * @Date ：2024-03-11 11:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

FramelessWidget::FramelessWidget(QWidget *parent)
    : QWidget(parent) {
    // 设置最小宽高
    this->setMinimumWidth(500);
    this->setMinimumHeight(300);

    // 设置背景色
    this->setStyleSheet("background:#303030");

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->setSpacing(10);
    layout->setContentsMargins(10, 10, 10, 10);

    QPushButton *btn1 = new QPushButton("确定");
    QPushButton *btn2 = new QPushButton("取消");

    layout->addWidget(btn1);
    layout->addWidget(btn2);

    QString style = R"(
        QPushButton {
            background-color: rgb(64, 64, 64);
            font:16px "Microsoft YaHei";
            color:rgb(200,200,200);
            border: 1px solid #707070;
            border-radius: 5px;
            padding: 5px;
        }
        QPushButton:hover {
            background-color: rgb(40, 40, 40);
        }
        QPushButton:pressed {
            background-color: rgb(64, 64, 64);
        }
    )";

    btn1->setStyleSheet(style);
    btn2->setStyleSheet(style);

    connect(btn1, &QPushButton::clicked, this, [ = ] { qDebug() << btn1->text(); });
    connect(btn2, &QPushButton::clicked, this, [ = ] { qDebug() << btn2->text(); });

    // 去除标题栏
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);

    // 将左键按下初始化为 false
    isLeftPressed = false;

    // 开启鼠标跟踪
    this->setMouseTracking(true);
}

FramelessWidget::~FramelessWidget() {}

void FramelessWidget::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        isLeftPressed = false;
    }
}

void FramelessWidget::mouseMoveEvent(QMouseEvent *event) {
    QPoint globalPos = event->globalPosition().toPoint();

    QRect rect = this->rect();
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());

    // 1. 鼠标未按下
    if (!isLeftPressed) {
        this->setCursorShape(globalPos);
        return;
    }
    // 2. 鼠标在 CENTER 位置按下
    if (location == CENTER) {
        move(globalPos - mousePos);
        event->accept();
        return;
    }
    // 3、鼠标在边缘位置按下
    QRect rMove(topLeft, bottomRight);
    switch (location) {
        case TOP:
            // 如果不加if判断，则窗口高度达到最小高度后，会被鼠标 "向下推走"
            if (bottomRight.y() - globalPos.y() > this->minimumHeight()) {
                rMove.setY(globalPos.y());
            }
            break;
        case BOTTOM:
            rMove.setHeight(globalPos.y() - topLeft.y());
            break;
        case LEFT:
            // 如果不加if判断，则窗口高度达到最小宽度后，会被鼠标 "向右推走"
            if (bottomRight.x() - globalPos.x() > this->minimumWidth()) {
                rMove.setX(globalPos.x());
            }
            break;
        case RIGHT:
            rMove.setWidth(globalPos.x() - topLeft.x());
            break;
        case TOP_LEFT:
            // 如果不加if判断，则窗口达到最小宽高后，会被鼠标 "向右下推走"
            if (bottomRight.x() - globalPos.x() > this->minimumWidth()) {
                rMove.setX(globalPos.x());
            }
            if (bottomRight.y() - globalPos.y() > this->minimumHeight()) {
                rMove.setY(globalPos.y());
            }
            break;
        case TOP_RIGHT:
            rMove.setWidth(globalPos.x() - topLeft.x());
            // 如果不加if判断，则窗口达到最小宽高后，会被鼠标 "向下推走"
            if (bottomRight.y() - globalPos.y() > this->minimumHeight()) {
                rMove.setY(globalPos.y());
            }
            break;
        case BOTTOM_LEFT:
            // 如果不加if判断，则窗口达到最小宽高后，会被鼠标 "向右推走"
            if (bottomRight.x() - globalPos.x() > this->minimumWidth()) {
                rMove.setX(globalPos.x());
            }
            rMove.setHeight(globalPos.y() - topLeft.y());
            break;
        case BOTTOM_RIGHT:
            rMove.setWidth(globalPos.x() - topLeft.x());
            rMove.setHeight(globalPos.y() - topLeft.y());
            break;
        default:
            break;
    }
    this->setGeometry(rMove);
}

void FramelessWidget::mousePressEvent(QMouseEvent *event) {
    switch (event->button()) {
        case Qt::LeftButton:
            isLeftPressed = true;
            if (location == CENTER) {
                mousePos = event->globalPosition().toPoint() - this->frameGeometry().topLeft();
            }
            break;
        case Qt::RightButton:
            this->close();
            break;
        default:
            break;
    }
}

void FramelessWidget::setCursorShape(const QPoint &cursorPoint) {
    QRect rect = this->rect();
    QPoint topLeft = mapToGlobal(rect.topLeft());
    QPoint bottomRight = mapToGlobal(rect.bottomRight());

    int x = cursorPoint.x();
    int y = cursorPoint.y();

    if (x >= topLeft.x() && x <= topLeft.x() + PADDING && y >= topLeft.y() && y <= topLeft.y() + PADDING) {
        // 左上角
        location = TOP_LEFT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if (x <= bottomRight.x() && x >= bottomRight.x() - PADDING && y <= bottomRight.y() && y >= bottomRight.y() - PADDING) {
        // 右下角
        location = BOTTOM_RIGHT;
        this->setCursor(QCursor(Qt::SizeFDiagCursor));
    } else if (x >= topLeft.x() && x <= topLeft.x() + PADDING && y <= bottomRight.y() && y >= bottomRight.y() - PADDING) {
        //左下角
        location = BOTTOM_LEFT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if (x <= bottomRight.x() && x >= bottomRight.x() - PADDING && y >= topLeft.y() && y <= topLeft.y() + PADDING) {
        // 右上角
        location = TOP_RIGHT;
        this->setCursor(QCursor(Qt::SizeBDiagCursor));
    } else if (x >= topLeft.x() && x <= topLeft.x() + PADDING) {
        // 左边
        location = LEFT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if (x <= bottomRight.x() && x >= bottomRight.x() - PADDING) {
        // 右边
        location = RIGHT;
        this->setCursor(QCursor(Qt::SizeHorCursor));
    } else if (y >= topLeft.y() && y <= topLeft.y() + PADDING) {
        // 上边
        location = TOP;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else if (y <= bottomRight.y() && y >= bottomRight.y() - PADDING) {
        // 下边
        location = BOTTOM;
        this->setCursor(QCursor(Qt::SizeVerCursor));
    } else {
        // 默认
        location = CENTER;
        this->setCursor(QCursor(Qt::ArrowCursor));
    }
}



