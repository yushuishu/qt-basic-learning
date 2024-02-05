#include "paint_widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QEvent>
#include <QDebug>

#include <QPainter>

// 温度曲线相关的宏
#define PADDING       50
// 温度曲线像素增量
#define INCREMENT     8
// 曲线描点的大小
#define POINT_RADIUS  4
// 温度文本相对于点的偏移
#define TEXT_OFFSET_X 12
// 温度文本相对于点的偏移
#define TEXT_OFFSET_Y 10


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:34
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：绘图事件
 * <p></p>
 */

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    // 添加一个Label，用于绘制高温曲线
    lblHigh = new QLabel(this);
    lblHigh->setText("");
    lblHigh->setFrameShape(QFrame::Box);
    verticalLayout->addWidget(lblHigh);

    // 添加一个Label，用于绘制低温曲线
    lblLow = new QLabel(this);
    lblLow->setText("");
    lblLow->setFrameShape(QFrame::Box);
    verticalLayout->addWidget(lblLow);

    // 为标签安装事件过滤器
    lblHigh->installEventFilter(this);
    lblLow->installEventFilter(this);

}

void PaintWidget::paintHigh() {
    QPainter painter(lblHigh);
    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 1. 计算 x 轴坐标
    int pointX[7] = {0};
    for (int i = 0; i < 7; i++) {
        pointX[i] = lblHigh->pos().x() + PADDING + (lblHigh->width() - PADDING * 2) / 6 * i;
    }

    // 2. 计算 y 轴坐标
    // 2.1 计算平均值
    int tempSum = 0;
    int tempAverage = 0;

    for (int i = 0; i < 7; i++) {
        tempSum += mHighTemp[i];
    }
    // 最高温平均值
    tempAverage = tempSum / 7;

    // 2.2 计算 y 轴坐标
    int pointY[7] = {0};
    int yCenter = lblHigh->height() / 2;
    int increment = lblHigh->height() / 20;
    for (int i = 0; i < 7; i++) {
        pointY[i] = yCenter - ((mHighTemp[i] - tempAverage) * increment);
    }

    // 3. 开始绘制
    // 3.1 初始化画笔
    QPen pen = painter.pen();
    //设置画笔宽度为1
    pen.setWidth(2);
    //设置颜色
    pen.setColor(QColor(255, 0, 0));
    painter.setPen(pen);
    //设置画刷颜色
    painter.setBrush(QColor(255, 0, 0));
    painter.setFont(QFont("Microsoft YaHei", 14));

    // 3.2 画点、写文本
    for (int i = 0; i < 7; i++) {
        painter.drawEllipse(QPoint(pointX[i], pointY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X, pointY[i] - TEXT_OFFSET_Y), QString::number(mHighTemp[i]) + "°");
    }

    // 3.3 绘制曲线
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            //虚线
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
        } else {
            // 实线
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i], pointY[i], pointX[i + 1], pointY[i + 1]);
    }
}

void PaintWidget::paintLow() {
    QPainter painter(lblLow);
    // 抗锯齿
    painter.setRenderHint(QPainter::Antialiasing, true);

    // 1. 计算 x 轴坐标
    int pointX[7] = {0};
    for (int i = 0; i < 7; i++) {
        pointX[i] = lblLow->pos().x() + PADDING + (lblLow->width() - PADDING * 2) / 6 * i;
    }

    // 2. 计算 y 轴坐标
    // 2.1 计算平均值
    int tempSum = 0;
    int tempAverage = 0;

    for (int i = 0; i < 7; i++) {
        tempSum += mLowTemp[i];
    }
    // 最高温平均值
    tempAverage = tempSum / 7;

    // 2.2 计算 y 轴坐标
    int pointY[7] = {0};
    int yCenter = lblLow->height() / 2;
    int increment = lblLow->height() / 20;
    for (int i = 0; i < 7; i++) {
        pointY[i] = yCenter - ((mLowTemp[i] - tempAverage) * increment);
    }

    // 3. 开始绘制
    // 3.1 初始化画笔
    QPen pen = painter.pen();
    // 设置画笔宽度为1
    pen.setWidth(2);
    // 设置颜色
    pen.setColor(QColor(0, 0, 255));
    painter.setPen(pen);
    //设置画刷颜色
    painter.setBrush(QColor(0, 0, 255));
    painter.setFont(QFont("Microsoft YaHei", 14));

    // 3.2 画点、写文本
    for (int i = 0; i < 7; i++) {
        painter.drawEllipse(QPoint(pointX[i], pointY[i]), POINT_RADIUS, POINT_RADIUS);
        painter.drawText(QPoint(pointX[i] - TEXT_OFFSET_X, pointY[i] - TEXT_OFFSET_Y), QString::number(mLowTemp[i]) + "°");
    }

    // 3.3 绘制曲线
    for (int i = 0; i < 6; i++) {
        if (i == 0) {
            //虚线
            pen.setStyle(Qt::DotLine);
            painter.setPen(pen);
        } else {
            // 实线
            pen.setStyle(Qt::SolidLine);
            painter.setPen(pen);
        }
        painter.drawLine(pointX[i], pointY[i], pointX[i + 1], pointY[i + 1]);
    }
}

bool PaintWidget::eventFIlter(QObject *watched, QEvent *event) {
    if (event->type() == QEvent::Paint) {
        if (watched == lblHigh) {
            paintHigh();
            qDebug() << "paint lblHigh";
        }
        if (watched == lblLow) {
            paintLow();
            qDebug() << "paint lblLow";
        }
    }
    return QWidget::eventFilter(watched, event);
}
