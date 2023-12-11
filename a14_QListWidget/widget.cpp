#include "widget.h"
#include "ui_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-08 08:27
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

QStringList iconStringList = {
    ":/icon/apple.ico",
    ":/icon/banana.ico",
    ":/icon/orange.ico",
    ":/icon/peach.ico",
    ":/icon/strawberry.ico"
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("列表框控件QListWidget");

    // 默认是列表模式
    mBtnGroup = new QButtonGroup(this);
    mBtnGroup->addButton(ui->rbListMode, 0);
    mBtnGroup->addButton(ui->rbIconMode, 1);
    connect(ui->rbListMode, &QRadioButton::clicked, this, &Widget::onRadioButtonClicked);
    connect(ui->rbIconMode, &QRadioButton::clicked, this, &Widget::onRadioButtonClicked);
    ui->rbListMode->setChecked(true);
    ui->lwProvince->setViewMode(QListView::ListMode);

    // 条目单击和双击的信号槽
    connect(ui->lwProvince, &QListWidget::itemClicked, this, &Widget::onItemClicked);
    connect(ui->lwProvince, &QListWidget::itemDoubleClicked, this, &Widget::onItemDoubleClicked);

    // add/insert/delete
    connect(ui->btnAdd, &QPushButton::clicked, this, &Widget::onBtnAddClicked);
    connect(ui->btnInsert, &QPushButton::clicked, this, &Widget::onBtnInsertClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &Widget::onBtnDeleteClicked);

}

Widget::~Widget()
{
    delete ui;
}
