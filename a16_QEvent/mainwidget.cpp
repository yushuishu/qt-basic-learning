#include "mainwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include "enter_leave_widget.h"
#include "press_move_release_widget.h"
#include "key_widget.h"
#include "timer_widget.h"
#include "drag_widget.h"
#include "paint_widget.h"
#include "context_widget.h"
#include "propagate_widget.h"


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 13:55
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent) {
    this->setWindowTitle("事件QEnvent");

    // 整体采用水平布局
    QHBoxLayout *horizontaLayout = new QHBoxLayout(this);
    horizontaLayout->setSpacing(0);
    horizontaLayout->setContentsMargins(0, 0, 0, 0);

    // 导航窗体
    navWidget = new QWidget(this);
    QVBoxLayout *leftLayout = new QVBoxLayout(navWidget);
    leftLayout->setSpacing(0);
    leftLayout->setContentsMargins(0, 0, 0, 0);

    horizontaLayout->addWidget(navWidget);

    // 主窗体
    mainWidget = new QWidget(this);
    mainWidget->setMinimumWidth(400);
    QVBoxLayout *rightLayout = new QVBoxLayout(mainWidget);
    rightLayout->setSpacing(0);
    rightLayout->setContentsMargins(0, 0, 0, 0);
    stackedWidget = new QStackedWidget(mainWidget);
    rightLayout->addWidget(stackedWidget);

    horizontaLayout->addWidget(mainWidget);


    initNav();
    initMain();
}

void MainWidget::initNav() {
    // 按钮文字集合
    QStringList names;
    names << "鼠标进入/离开"
        << "鼠标按下/移动/释放"
        << "键盘事件"
        << "定时器事件"
        << "拖动事件"
        << "绘图事件"
        << "右键菜单"
        << "总结：事件的传递流程";

    btnGroup = new QButtonGroup(this);

    //自动生成按钮
    for (int i = 0; i < names.count(); i++) {
        QPushButton *btn = new QPushButton;
        //设置按钮固定高度
        btn->setMinimumHeight(60);
        //设置按钮的文字
        btn->setText(QString("%1. %2").arg(i + 1, 2, 10, QChar('0')).arg(names.at(i)));
        //设置按钮可选中按下类似复选框的功能
        btn->setCheckable(true);
        // 设置按钮的样式
        navWidget->setStyleSheet(R"(
            QPushButton {
                font: 25px;
                text-align : left;
            }
        )");
        // 将按钮添加到 btnGroup
        btnGroup->addButton(btn, i);
        //将按钮加入到布局
        navWidget->layout()->addWidget(btn);
        // 关联信号槽
        connect(btn, &QPushButton::clicked, this, &MainWidget::btnClicked);
        // 默认选中第一项
        btnGroup->button(0)->click();
    }
}

void MainWidget::initMain() {
    // 逐个添加子窗体
    stackedWidget->addWidget(new EnterLeaveWidget());
    stackedWidget->addWidget(new PressMoveReleaseWidget());
    stackedWidget->addWidget(new KeyWidget());
    stackedWidget->addWidget(new TimerWidget());
    stackedWidget->addWidget(new DragWidget());
    stackedWidget->addWidget(new PaintWidget());
    stackedWidget->addWidget(new ContextWidget());
    stackedWidget->addWidget(new PropagateWidget());
}

void MainWidget::btnClicked() {
    int index = btnGroup->checkedId();
    stackedWidget->setCurrentIndex(index);
}

MainWidget::~MainWidget() {}
