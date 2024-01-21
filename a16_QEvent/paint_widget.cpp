#include "paint_widget.h"

#include <QLabel>
#include <QVBoxLayout>

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

}
