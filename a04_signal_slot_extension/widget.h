#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "commander.h"
#include "soldier.h"

/**
 * @Author ：谁书-ss
 * @Date ：2023-08-19 21:47
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    // 添加 commander 和 soldier 两个指针类型的成员变量
    Commander *commander5;
    Soldier *soldier5;

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
