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

    ui->twStudent->setItem(count, 0, nameItem);
    ui->twStudent->setItem(count, 1, genderItem);
    ui->twStudent->setItem(count, 2, ageItem);
    ui->twStudent->setItem(count, 3, provinceItem);

}
