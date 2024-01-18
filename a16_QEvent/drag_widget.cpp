#include "drag_widget.h"

#include <QVBoxLayout>
#include <texteditx.h>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:32
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：拖动事件
 * <p></p>
 */

DragWidget::DragWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(10, 10, 10, 10);

    // 添加自定义控件TextEditX
    TextEditX *textEditx = new TextEditX(this);
    textEditx->setPlaceholderText("支持文件拖放的方式，来打开文件");
    verticalLayout->addWidget(textEditx);
}
