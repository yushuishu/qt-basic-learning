#include "widget.h"
#include "ui_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-07 14:22
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
    this->setWindowTitle("QProgressBar进度条控件");

    // 1.下载
    ui->pgbFileDownload->setMinimum(0);
    ui->pgbFileDownload->setMaximum(100);
    // ui->pbDownload->setRange(0, 100);

    ui->pgbFileDownload->setValue(0);

    // 设置文本的显示位置
    ui->pgbFileDownload->setAlignment(Qt::AlignRight);
    // 设置是否显示文本
    // ui->pbDownload->setTextVisible(false);

    mTimerFileDownload = new QTimer();
    mTimerFileDownload->setInterval(10);

    connect(ui->btnFileDownload, &QPushButton::clicked, this, &Widget::btnFileDownload);
    connect(mTimerFileDownload, &QTimer::timeout, this, &Widget::onFileDownloadTimeout);

    // 2.拷贝
    ui->pgbFileCopy->setMinimum(0);
    ui->pgbFileCopy->setMaximum(1000);
    // ui->pbCopy->setRange(0, 1000);

    ui->pgbFileCopy->setValue(0);

    // 设置文本的显示位置
    ui->pgbFileCopy->setAlignment(Qt::AlignCenter);
    // 显示格式
    ui->pgbFileCopy->setFormat("%v/%m");

    mTimerFileCopy = new QTimer();
    mTimerFileCopy->setInterval(5);

    connect(ui->btnFileCopy, &QPushButton::clicked, this, &Widget::btnFileCopy);
    connect(mTimerFileCopy, &QTimer::timeout, this, &Widget::onFileCopyTimeout);


    // 3、网络
    ui->pgbNetwork->setMinimum(0);
    ui->pgbNetwork->setMaximum(0);

}

Widget::~Widget() {
    delete ui;
}

void Widget::btnFileDownload() {
    ui->pgbFileDownload->reset();
    // 启动定时器
    mTimerFileDownload->start();
}

void Widget::btnFileCopy() {
    ui->pgbFileCopy->reset();
    // 启动定时器
    mTimerFileCopy->start();
}

void Widget::onFileDownloadTimeout() {
    int currentValue = ui->pgbFileDownload->value();

    if(currentValue >= ui->pgbFileDownload->maximum()) {
        mTimerFileDownload->stop();
        QMessageBox::information(this, "提示", "文件下载完成！");
    } else {
        ui->pgbFileDownload->setValue(ui->pgbFileDownload->value() + 1);
        qDebug() << ui->pgbFileDownload->value();
    }
}

void Widget::onFileCopyTimeout() {
    int currentValue = ui->pgbFileCopy->value();

    if(currentValue >= ui->pgbFileCopy->maximum()) {
        mTimerFileCopy->stop();
        QMessageBox::information(this, "提示", "文件拷贝完成！");
    } else {
        ui->pgbFileCopy->setValue(ui->pgbFileCopy->value() + 1);
        qDebug() << ui->pgbFileCopy->value();
    }
}
