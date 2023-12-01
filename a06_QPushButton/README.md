# a06_QPushButton

## 学习内容

QPushButton 是 Qt中的按钮，通常用于用户的点击，然后执行相应操作。

- 字体、字体颜色、Icon
- 按钮样式
- 按钮事件：按下、抬起

## 案例

**效果**
![Img](./FILES/README.md/img-20231201220110.png)


**代码**

`widget.h` 头文件
```c++
#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

/**
 * @Author ：谁书-ss
 * @Date ：2023-11-30 12:55
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

private slots:
    void startStopButton();
    void connectButton();
    void signalButtonClicked();
    void signalButtonPressed();
    void signalButtonReleased();

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
 * @Date ：2023-11-30 12:55
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 启动、停止
    this->startStopButton();
    connect(ui->startStopButton, &QPushButton::clicked, this, &Widget::startStopButton);
    // 连接 禁止
    ui->sendCommandButton->setEnabled(false);
    connect(ui->connectButton, &QPushButton::clicked, this, &Widget::connectButton);
    // 样式
    ui->styleButton->setStyleSheet("color:rgb(255, 0, 0);background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));");
    // 信号：按下、抬起
    connect(ui->signalButton, &QPushButton::clicked, this, &Widget::signalButtonClicked);
    connect(ui->signalButton, &QPushButton::pressed, this, &Widget::signalButtonPressed);
    connect(ui->signalButton, &QPushButton::released, this, &Widget::signalButtonReleased);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startStopButton() {
    QString  btnText = ui->startStopButton->text();

    if(btnText == "启动") {
        // 设置文本和字体
        ui->startStopButton->setText("停止");
        ui->startStopButton->setFont(QFont("黑体", 16));
        // 设置图标
        ui->startStopButton->setIcon(QIcon(":/files/stop.png"));
        ui->startStopButton->setIconSize(QSize(48, 48));
    } else {
        ui->startStopButton->setText("启动");
        ui->startStopButton->setFont(QFont("黑体", 12));
        ui->startStopButton->setIcon(QIcon(":/files/start.png"));
        ui->startStopButton->setIconSize(QSize(48, 48));
    }
}

void Widget::connectButton() {
    QString s = ui->connectButton->text();
    if(s == "断开连接") {
        ui->connectButton->setText("连接");
        ui->sendCommandButton->setEnabled(false);
    } else {
        ui->connectButton->setText("断开连接");
        ui->sendCommandButton->setEnabled(true);
    }
}

// 按钮抬起时，发射clicked信号
void Widget::signalButtonClicked() {
    qDebug() << "Clicked。。。";
}
// 按钮按下时，发射pressed信号
void Widget::signalButtonPressed() {
    qDebug() << "Pressed。。。";
}
// 按钮抬起时，发射released信号
void Widget::signalButtonReleased() {
    qDebug() << "Released。。。";
}


```
