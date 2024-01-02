#include "widget.h"
#include "ui_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-12 08:49
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

    // 设置单元格的列
    ui->twStudent->setColumnCount(4);

    QStringList horizontalList;
    horizontalList << "姓名";
    horizontalList << "性别";
    horizontalList << "年龄";
    horizontalList << "籍贯";

    ui->twStudent->setHorizontalHeaderLabels(horizontalList);

    // 设置列的宽度
    ui->twStudent->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 设置初始化数据
    this->appendOneRow("李雷", "男", 20, "广东");
    this->appendOneRow("韩梅梅", "女", 22, "上海");
    this->appendOneRow("林涛", "男", 23, "北京");
    this->appendOneRow("小黑", "男", 25, "深圳");
    this->appendOneRow("小红", "女", 24, "杭州");

    // 设置行表头是否显示
    if(ui->twStudent->horizontalHeader()->isHidden()) {
        ui->cboHHeader->setChecked(false);
    } else {
        ui->cboHHeader->setChecked(true);
    }
    connect(ui->cboHHeader, &QCheckBox::stateChanged, this, [=](int state){
        if(state == Qt::Checked) {
            ui->twStudent->horizontalHeader()->show();
        } else {
            ui->twStudent->horizontalHeader()->hide();
        }
    });

    // 设置列表头
    // 首先根据在属性窗口中设置的属性，初始化复选框
    if(ui->twStudent->verticalHeader()->isHidden()) {
        ui->cboVHeader->setChecked(false);
    } else {
        ui->cboVHeader->setChecked(true);
    }
    // 点击复选框时，显示或者隐藏列表头
    connect(ui->cboVHeader, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->verticalHeader()->show();
        } else if(state == Qt::Unchecked) {
            ui->twStudent->verticalHeader()->hide();
        }
    });

    // 交替显示行的背景色
    // 首先根据在属性窗口中设置的属性，初始化复选框
    if(ui->twStudent->alternatingRowColors()) {
        ui->cboAlternate->setChecked(true);
    } else {
        ui->cboAlternate->setChecked(false);
    }
    // 点击复选框时，使能或者禁能交替背景色
    connect(ui->cboAlternate, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            ui->twStudent->setAlternatingRowColors(true);
        } else if(state == Qt::Unchecked) {
            ui->twStudent->setAlternatingRowColors(false);
        }
    });

    // 设置单元格是否可编辑
    // 首先根据在属性窗口中设置的属性，初始化复选按钮
    int trigger = ui->twStudent->editTriggers();
    if(trigger == QAbstractItemView::NoEditTriggers) {
        ui->cboEditCell->setChecked(false);
    } else {
        ui->cboEditCell->setChecked(true);
    }
    // 点击复选按钮时，使能或者禁能单元格编辑
    connect(ui->cboEditCell, &QCheckBox::stateChanged, this, [=](int state) {
        if(state == Qt::Checked) {
            // 当双击单元格/选中单元格然后单击/按下编辑键F2，都可以编辑单元格。
            ui->twStudent->setEditTriggers(QAbstractItemView::DoubleClicked |
                                           QAbstractItemView::SelectedClicked |
                                           QAbstractItemView::EditKeyPressed);
        } else if(state == Qt::Unchecked) {
            ui->twStudent->setEditTriggers(QAbstractItemView::NoEditTriggers);
        }
    });

    // 设置行选择还是单元格选择

}

Widget::~Widget()
{
    delete ui;
}

void Widget::appendOneRow(QString name, QString gender, int age, QString province)
{
    int count = ui->twStudent->rowCount();

    ui->twStudent->setRowCount(count + 1);

    QTableWidgetItem *nameItem = new QTableWidgetItem(name);
    QTableWidgetItem *genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem *ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem *provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    ui->twStudent->setItem(count, 0, nameItem);
    ui->twStudent->setItem(count, 1, genderItem);
    ui->twStudent->setItem(count, 2, ageItem);
    ui->twStudent->setItem(count, 3, provinceItem);

}
