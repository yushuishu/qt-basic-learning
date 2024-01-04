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
    this->setWindowTitle("表格控件QTableWidget");

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
    this->appendOneRow("刘备", "男", 20, "广东");
    this->appendOneRow("貂蝉", "女", 22, "上海");
    this->appendOneRow("曹操", "男", 23, "北京");
    this->appendOneRow("诸葛亮", "男", 25, "深圳");
    this->appendOneRow("小乔", "女", 24, "杭州");

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

    // 设置样式
    connect(ui->btnStyleSheet, &QPushButton::clicked, this, &Widget::btnStyleSheetClicked);

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
    // 首先根据在属性窗口中设置的属性，初始化单选按钮的选中状态
    int selectionBehavior = ui->twStudent->selectionBehavior();
    if(selectionBehavior == QAbstractItemView::SelectItems) {
        ui->rbCell->setChecked(true);
    } else if(selectionBehavior == QAbstractItemView::SelectRows){
        ui->rbRow->setChecked(true);
    }
    // 点击单选按钮时，使能单元格选中或者行选中
    mButtonGroupSelection = new QButtonGroup(this);
    mButtonGroupSelection->addButton(ui->rbCell, 0);
    mButtonGroupSelection->addButton(ui->rbRow, 1);
    connect(ui->rbCell, &QRadioButton::clicked, this, &Widget::onSelectionRadioButtonClicked);
    connect(ui->rbRow, &QRadioButton::clicked, this, &Widget::onSelectionRadioButtonClicked);

    // 单元格点击时， 将对应行的数据显示到文本框
    connect(ui->twStudent, &QTableWidget::itemClicked, this, &Widget::onItemClicked);

    // 添加一行
    connect(ui->btnAppend, &QPushButton::clicked, this, &Widget::btnAppendClicked);
    // 插入一行
    connect(ui->btnInsert, &QPushButton::clicked, this, &Widget::btnInsertClicked);
    // 删除一行
    connect(ui->btnDelete, &QPushButton::clicked, this, &Widget::btnDeleteClicked);
    // 修改当前行
    connect(ui->btnModify, &QPushButton::clicked, this, &Widget::btnModifyClicked);
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

void Widget::btnStyleSheetClicked()
{
    QString cellStyle = R"(
        QTableView
        {
            text-align:center;
            background-color: rgba(255, 255, 255, 0);
            alternate-background-color:#e3edf9;
            font:14px "微软雅黑";
            color:#677483;
            gridline-color: #ccddf0;
        }
    )";


    const QString horizontalHeaderStyle = R"(
        QHeaderView::section {
            color: black;
            font:bold 14px "微软雅黑";
            text-align:center;
            height:32px;
            background-color: #d1dff0;
            border:1px solid #8faac9;
            border-left:none;
        }
    )";

    const QString verticalHeaderStyle = R"(
        QHeaderView::section {
            color: black;
            font:bold 14px "微软雅黑";
            width:60px;
            text-align:center;

            background-color: #d1dff0;
            border:1px solid #8faac9;
            border-left:none;
        }
    )";

    ui->twStudent->setStyleSheet(cellStyle);
    ui->twStudent->horizontalHeader()->setStyleSheet(horizontalHeaderStyle);
    ui->twStudent->verticalHeader()->setStyleSheet(verticalHeaderStyle);
}

void Widget::onSelectionRadioButtonClicked()
{
    int checkedId = mButtonGroupSelection->checkedId();
    if(checkedId == 0) {
        ui->twStudent->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->twStudent->setSelectionBehavior(QAbstractItemView::SelectItems);
    } else if(checkedId == 1) {
        ui->twStudent->setSelectionMode(QAbstractItemView::SingleSelection);
        ui->twStudent->setSelectionBehavior(QAbstractItemView::SelectRows);
    }
}

void Widget::onItemClicked(QTableWidgetItem *item)
{
    int row = item->row();

    QString name = ui->twStudent->item(row, 0)->text();
    QString gender = ui->twStudent->item(row, 1)->text();
    QString age = ui->twStudent->item(row, 2)->text();
    QString province = ui->twStudent->item(row, 3)->text();

    ui->leName->setText(name);
    ui->leGender->setText(gender);
    ui->leAge->setText(age);
    ui->leProvince->setText(province);
}

void Widget::insertOneRow(int row, QString name, QString gender, int age, QString province)
{
    ui->twStudent->insertRow(row);

    // 上面 insertRow 只是插入一个空行，需要手动添加每个单元格的内容
    QTableWidgetItem* nameItem = new QTableWidgetItem(name);
    QTableWidgetItem* genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem* ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem* provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    ui->twStudent->setItem(row, 0, nameItem);
    ui->twStudent->setItem(row, 1, genderItem);
    ui->twStudent->setItem(row, 2, ageItem);
    ui->twStudent->setItem(row, 3, provinceItem);
}

void Widget::btnAppendClicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    appendOneRow(name, gender, age, province);
}

void Widget::btnInsertClicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    // 获取当前选中的行号
    int currentRow = ui->twStudent->currentRow();

    insertOneRow(currentRow, name, gender, age, province);
}

void Widget::btnDeleteClicked()
{
    // 获取当前选中的行号
    int currentRow = ui->twStudent->currentRow();
    ui->twStudent->removeRow(currentRow);
}

void Widget::btnModifyClicked()
{
    QString name = ui->leName->text();
    QString gender = ui->leGender->text();
    int age = ui->leAge->text().toInt();
    QString province = ui->leProvince->text();

    // 获取当前选中的行号
    int currentRow = ui->twStudent->currentRow();

    QTableWidgetItem* nameItem = new QTableWidgetItem(name);
    QTableWidgetItem* genderItem = new QTableWidgetItem(gender);
    QTableWidgetItem* ageItem = new QTableWidgetItem(QString::number(age));
    QTableWidgetItem* provinceItem = new QTableWidgetItem(province);

    nameItem->setTextAlignment(Qt::AlignCenter);
    genderItem->setTextAlignment(Qt::AlignCenter);
    ageItem->setTextAlignment(Qt::AlignCenter);
    provinceItem->setTextAlignment(Qt::AlignCenter);

    ui->twStudent->setItem(currentRow, 0, nameItem);
    ui->twStudent->setItem(currentRow, 1, genderItem);
    ui->twStudent->setItem(currentRow, 2, ageItem);
    ui->twStudent->setItem(currentRow, 3, provinceItem);
}
