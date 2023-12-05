#include "widget.h"
#include "ui_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-05 16:24
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

QStringList gdCityList = {"广州市", "深圳市", "珠海市", "东莞市"};
QStringList zjCityList = {"杭州市", "宁波市", "温州市", "绍兴市"};
QStringList sdCityList = {"济南市", "青岛市", "烟台市", "威海市"};
QStringList hbCityList = {"石家庄市", "保定市", "廊坊市", "衡水市"};
QStringList nmCityList = {"呼和浩特市", "包头市", "呼伦贝尔市", "赤峰市"};
QStringList hnCityList = {"郑州市", "新乡市", "鹤壁市", "安阳市", "濮阳市"};

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget) {
    ui->setupUi(this);
    this->setWindowTitle("学习QcomboBox组件");

    // 添加大学
    ui->cboUniversity->addItem("清华大学");
    ui->cboUniversity->addItem("北京大学");
    ui->cboUniversity->addItem("中国人民大学");

    // 添加省份
    ui->cboProvince->addItem("广东省");
    ui->cboProvince->addItem("浙江省");
    ui->cboProvince->addItem("山东省");
    ui->cboProvince->addItem("河北省");
    ui->cboProvince->addItem("内蒙古自治区省");
    ui->cboProvince->addItem("河南省");

    // 为省份条目添加图标
    ui->cboProvince->setItemIcon(0, QIcon(":/icon/gd.ico"));
    ui->cboProvince->setItemIcon(1, QIcon(":/icon/zj.ico"));
    ui->cboProvince->setItemIcon(2, QIcon(":/icon/sd.ico"));
    ui->cboProvince->setItemIcon(3, QIcon(":/icon/hb.ico"));
    ui->cboProvince->setItemIcon(4, QIcon(":/icon/nm.ico"));
    ui->cboProvince->setItemIcon(5, QIcon(":/icon/he.ico"));
    // 默认选中第一项-广东省
    ui->cboProvince->setCurrentIndex(0);

    // 添加城市
    ui->cboCity->addItems(gdCityList);

    // 信号槽
    connect(ui->cboUniversity, &QComboBox::currentIndexChanged, this, &Widget::onCboUniversityChanged);
    connect(ui->cboProvince, &QComboBox::currentIndexChanged, this, &Widget::onCboProvinceChanged);
    connect(ui->cboCity, &QComboBox::currentIndexChanged, this, &Widget::onCboCityChanged);

    // 姓名文本框变化时，更新结果
    connect(ui->leName, &QLineEdit::textChanged, this, &Widget::onLineEditChanged);

}

Widget::~Widget() {
    delete ui;
}

void Widget::onCboUniversityChanged(int index) {
    // 获取姓名、大学、省份、城市
    QString name = ui->leName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    if(!name.isEmpty()) {
        ui->leResult->setText(name + "毕业于" + university + ", 来自" + province + city);
    }
}

void Widget::onCboProvinceChanged(int index) {
    // 先将city对应的列表清空
    ui->cboCity->clear();

    switch (index) {
    case 0:
        ui->cboCity->addItems(gdCityList);
        break;
    case 1:
        ui->cboCity->addItems(zjCityList);
        break;
    case 2:
        ui->cboCity->addItems(sdCityList);
        break;
    case 3:
        ui->cboCity->addItems(hbCityList);
        break;
    case 4:
        ui->cboCity->addItems(nmCityList);
        break;
    case 5:
        ui->cboCity->addItems(hnCityList);
        break;
    default:
        break;
    }

    // 获取姓名、大学、省份、城市
    QString name = ui->leName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    if(!name.isEmpty()) {
        ui->leResult->setText(name + "毕业于" + university + ", 来自" + province + city);
    }
}

void Widget::onCboCityChanged(int index) {
    // 获取姓名、大学、省份、城市
    QString name = ui->leName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    if(!name.isEmpty()) {
        ui->leResult->setText(name + "毕业于" + university + ", 来自" + province + city);
    }
}

void Widget::onLineEditChanged() {
    // 获取姓名、大学、省份、城市
    QString name = ui->leName->text();
    QString university = ui->cboUniversity->currentText();
    QString province = ui->cboProvince->currentText();
    QString city = ui->cboCity->currentText();

    if(!name.isEmpty()) {
        ui->leResult->setText(name + "毕业于" + university + ", 来自" + province + city);
    }
}
