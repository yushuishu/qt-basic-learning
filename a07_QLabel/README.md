# a07_QLabel

## 学习内容

`QLabel`是Qt中的标签类，通常用于显示提示性的文本，也可以显示图像


## 属性和方法

**效果**

![Img](./FILES/README.md/img-20231203144502.png)

`widget.h` 头文件
```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-01 22:07
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void printAlignment();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

```

`widget.cpp` 源文件
```c++
#include "widget.h"
#include "ui_widget.h"

#include "QDebug"

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-01 22:07
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("文本标签Label对齐方式");

    // 设置样式
    ui->label_1->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_2->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_3->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_4->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_5->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_6->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_7->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_8->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    ui->label_9->setStyleSheet("color:rgb(255, 0, 0);background-color:rgb(227, 227, 227);");
    // 获取和设置按钮上显示的文本
    ui->label_1->setText("水平方向-左对齐");
    ui->label_2->setText("水平方向-右对齐");
    ui->label_3->setText("水平方向-居中对齐");
    ui->label_4->setText("垂直方向-上对齐");
    ui->label_5->setText("垂直方向-下对齐");
    ui->label_6->setText("垂直方向-居中对齐");
    ui->label_7->setText("垂直方向和水平方向-居中对齐");
    ui->label_8->setText("文本是否换行，文本是否换行，文本是否换行，文本是否换行。");
    ui->label_9->setText("设置图像");

    // 获取文本标签对齐方式
    this->printAlignment();

    // 水平方向-左对齐
    ui->label_1->setAlignment(Qt::AlignLeft);
    // 水平方向-右对齐
    ui->label_2->setAlignment(Qt::AlignRight);
    // 水平方向-居中对齐
    ui->label_3->setAlignment(Qt::AlignHCenter);
    // 垂直方向-上对齐
    ui->label_4->setAlignment(Qt::AlignTop);
    // 垂直方向-下对齐
    ui->label_5->setAlignment(Qt::AlignBottom);
    // 垂直方向-居中对齐
    ui->label_6->setAlignment(Qt::AlignVCenter);
    // 垂直方向和水平方向-居中对齐 Qt::AlignCenter（AlignVCenter | AlignHCenter）
    ui->label_7->setAlignment(Qt::AlignCenter);

    // 再次获取文本标签对齐方式
    this->printAlignment();


    // 文本换行 true：换行  false：不换行
    qDebug() << "文本是否换行：" << ui->label_8->wordWrap();
    ui->label_8->setWordWrap(true);
    qDebug() << "文本是否换行：" << ui->label_8->wordWrap();


    // 图像
    QPixmap pix(":/files/cat.png");
    ui->label_9->setPixmap(pix);

}

Widget::~Widget() {
    delete ui;
}

void Widget::printAlignment() {
    qDebug() << "------------------------------------- 获取文本对齐方式";
    auto localAlignment1 = ui->label_1->alignment();
    auto localAlignment2 = ui->label_2->alignment();
    auto localAlignment3 = ui->label_3->alignment();
    auto localAlignment4 = ui->label_4->alignment();
    auto localAlignment5 = ui->label_5->alignment();
    auto localAlignment6 = ui->label_6->alignment();
    auto localAlignment7 = ui->label_7->alignment();
    qDebug() << "label_1-水平方向-左对齐" << localAlignment1;
    qDebug() << "label_2-水平方向-右对齐" << localAlignment2;
    qDebug() << "label_3-水平方向-居中对齐" << localAlignment3;
    qDebug() << "label_4-垂直方向-上对齐" << localAlignment4;
    qDebug() << "label_5-垂直方向-下对齐" << localAlignment5;
    qDebug() << "label_6-垂直方向-居中对齐" << localAlignment6;
    qDebug() << "label_7-垂直方向-居中对齐" << localAlignment7;
}

```


