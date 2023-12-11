#include "widget.h"
#include "ui_widget.h"

#include "QDebug"
#include "QRandomGenerator"

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
    ":/FILES/chijing.png",
    ":/FILES/ku.png",
    ":/FILES/nu.png",
    ":/FILES/xiao.png",
    ":/FILES/zhayan.png"
};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("列表框控件QListWidget");

    // 添加默认条目
    QListWidgetItem *item1 = new QListWidgetItem();
    item1->setText("广东省");
    item1->setIcon(QIcon(":/FILES/chijing.png"));
    ui->lwProvince->addItem(item1);

    QListWidgetItem *item2 = new QListWidgetItem();
    item2->setText("河南省");
    item2->setIcon(QIcon(":/FILES/xiao.png"));
    ui->lwProvince->addItem(item2);

    QListWidgetItem *item3 = new QListWidgetItem();
    item3->setText("山东省");
    item3->setIcon(QIcon(":/FILES/zhayan.png"));
    ui->lwProvince->addItem(item3);

    // 默认是列表模式
    operateButtonGroup = new QButtonGroup(this);
    operateButtonGroup->addButton(ui->rbListMode, 0);
    operateButtonGroup->addButton(ui->rbIconMode, 1);
    ui->rbListMode->setChecked(true);
    ui->lwProvince->setViewMode(QListView::ListMode);
    connect(ui->rbListMode, &QRadioButton::clicked, this, &Widget::rbModeClicked);
    connect(ui->rbIconMode, &QRadioButton::clicked, this, &Widget::rbModeClicked);

    // 条目单击和双击的信号槽
    connect(ui->lwProvince, &QListWidget::itemClicked, this, &Widget::onItemClicked);
    connect(ui->lwProvince, &QListWidget::itemDoubleClicked, this, &Widget::onItemDoubleClicked);

    // add/insert/delete
    connect(ui->btnAdd, &QPushButton::clicked, this, &Widget::onBtnAddClicked);
    connect(ui->btnInsert, &QPushButton::clicked, this, &Widget::onBtnInsertClicked);
    connect(ui->btnDelete, &QPushButton::clicked, this, &Widget::onBtnDeleteClicked);

}

Widget::~Widget() {
    delete ui;
}

// 单选按钮，选择显示模式
void Widget::rbModeClicked() {
    int localCheckedId = operateButtonGroup->checkedId();
    if (localCheckedId == 0) {
        //列表模式
        ui->lwProvince->setViewMode(QListView::ListMode);
        // 条目间距
        ui->lwProvince->setSpacing(2);
    } else if (localCheckedId == 1) {
        //图标模式
        ui->lwProvince->setViewMode(QListView::IconMode);
        // 条目间距
        ui->lwProvince->setSpacing(10);
    } else {
        qDebug() << "无效模式选择";

    }

}
// 单击 选中
void Widget::onItemClicked(QListWidgetItem *item) {
    ui->leCurrentItem->setText(item->text());
}

// 双击 可编辑
void Widget::onItemDoubleClicked(QListWidgetItem *item) {
    item->setFlags(Qt::ItemIsEditable | Qt::ItemIsSelectable | Qt::ItemIsEnabled);
}

// 添加
void Widget::onBtnAddClicked() {
    // 获取 0-4 随机数
    int iconIndex = QRandomGenerator::global()->generate() % 5;

    QIcon icon(iconStringList[iconIndex]);
    QString text = ui->leInput->text();
    if(text.isEmpty()) {
        qDebug() << "添加内容不能为空";
    }
    QListWidgetItem *item = new QListWidgetItem(icon, text);

    ui->lwProvince->addItem(item);
}

// 插入
void Widget::onBtnInsertClicked() {
    // 获取 0-4 随机数
    int iconIndex = QRandomGenerator::global()->generate() % 5;

    QIcon icon(iconStringList[iconIndex]);
    QString text = ui->leInput->text();
    if(text.isEmpty()) {
        qDebug() << "插入内容不能为空";
    }
    QListWidgetItem *item = new QListWidgetItem(icon, text);

    // 获取当前选中的行
    int localCurrentRow = ui->lwProvince->currentRow();

    ui->lwProvince->insertItem(localCurrentRow, item);
}

void Widget::onBtnDeleteClicked() {
#if 0
    // 方法一
    QListWidgetItem* item = ui->lwProvince->currentItem();
    ui->lwProvince->removeItemWidget(item);
    delete item;
#else
    // 方法二
    int row = ui->lwProvince->currentRow();
    QListWidgetItem* item = ui->lwProvince->takeItem(row);
    delete item;
#endif
}
