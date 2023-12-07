#include "widget.h"
#include "ui_widget.h"

#include "qdebug.h"
#include "qvalidator.h"

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-07 10:39
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
    this->setWindowTitle("QSlider滑动条控件");

    // 初始化红色滑动条
    ui->hsRed->setMinimum(0);
    ui->hsRed->setMaximum(255);
    // ui->hsRed->setRange(0, 255);


    ui->hsRed->setSingleStep(1);
    ui->hsRed->setPageStep(10);

    ui->hsRed->setOrientation(Qt::Horizontal);

    // 初始化绿色滑动条
    ui->hsGreen->setMinimum(0);
    ui->hsGreen->setMaximum(255);
    // ui->hsGreen->setRange(0, 255);

    ui->hsGreen->setSingleStep(5);
    ui->hsGreen->setPageStep(20);

    ui->hsGreen->setOrientation(Qt::Horizontal);

    // 初始化蓝色滑动条
    ui->hsBlue->setMinimum(0);
    ui->hsBlue->setMaximum(255);
    // ui->hsBlue->setRange(0, 255);

    ui->hsBlue->setSingleStep(10);
    ui->hsBlue->setPageStep(50);

    ui->hsBlue->setOrientation(Qt::Horizontal);

    // 初始化文本框的显示和背景色
    QString red = QString::number(ui->hsRed->value());
    QString green = QString::number(ui->hsGreen->value());
    QString blue = QString::number(ui->hsBlue->value());
    ui->leRedResult->setText(red);
    ui->leGreenResult->setText(green);
    ui->leBlueResult->setText(blue);

    QString style = "background-color: rgb(" + red + "," +  green + ","  + blue + ");";
    ui->leResult->setStyleSheet(style);
    ui->leResult->setEnabled(false);


    // 连接滑动条控件
    connect(ui->hsRed, &QSlider::sliderMoved, this, &Widget::hsRedChanged);
    connect(ui->hsGreen, &QSlider::sliderMoved, this, &Widget::hsGreenChanged);
    connect(ui->hsBlue, &QSlider::sliderMoved, this, &Widget::hsBlueChanged);


    // 输入框，只能是整数，且限制最小最大值
    ui->leRedResult->setValidator(new QIntValidator(this));
    ui->leGreenResult->setValidator(new QIntValidator(this));
    ui->leBlueResult->setValidator(new QIntValidator(this));

    // 连接输入框，直接输入一个值，更改颜色，并更改滑块
    connect(ui->leRedResult, &QLineEdit::textChanged, this, &Widget::leRedResultChanged);
    connect(ui->leGreenResult, &QLineEdit::textChanged, this, &Widget::leGreenResultChanged);
    connect(ui->leBlueResult, &QLineEdit::textChanged, this, &Widget::leBlueResultChanged);
}

Widget::~Widget() {
    delete ui;
}

void Widget::hsRedChanged(int value) {
    // 获取rgb的值
    //QString redNumber = QString::number(ui->hsRed->value());
    QString redNumber = QString::number(value);
    QString greenNumber = QString::number(ui->hsGreen->value());
    QString blueNumber = QString::number(ui->hsBlue->value());

    // 显示右侧文本框
    ui->leRedResult->setText(redNumber);

    // 颜色结果
    QString style = "background-color: rgb(" + redNumber + "," +  greenNumber + ","  + blueNumber + ");";
    qDebug() << style;
    ui->leResult->setStyleSheet(style);
}

void Widget::hsGreenChanged(int value) {
    // 获取rgb的值
    QString redNumber = QString::number(ui->hsRed->value());
    QString greenNumber = QString::number(value);
    QString blueNumber = QString::number(ui->hsBlue->value());

    // 显示右侧文本框
    ui->leGreenResult->setText(greenNumber);

    // 颜色结果
    QString style = "background-color: rgb(" + redNumber + "," +  greenNumber + ","  + blueNumber + ");";
    qDebug() << style;
    ui->leResult->setStyleSheet(style);
}

void Widget::hsBlueChanged(int value) {
    // 获取rgb的值
    QString redNumber = QString::number(ui->hsRed->value());
    QString greenNumber = QString::number(ui->hsGreen->value());
    QString blueNumber = QString::number(value);

    // 显示右侧文本框
    ui->leBlueResult->setText(blueNumber);

    // 颜色结果
    QString style = "background-color: rgb(" + redNumber + "," +  greenNumber + ","  + blueNumber + ");";
    qDebug() << style;
    ui->leResult->setStyleSheet(style);
}

void Widget::leRedResultChanged(const QString &arg1) {
    int value = arg1.toInt();
    ui->hsRed->setValue(value);
    hsRedChanged(value);
}

void Widget::leGreenResultChanged(const QString &arg1) {
    int value = arg1.toInt();
    ui->hsGreen->setValue(value);
    hsGreenChanged(value);
}

void Widget::leBlueResultChanged(const QString &arg1) {
    int value = arg1.toInt();
    ui->hsBlue->setValue(value);
    hsBlueChanged(value);
}
