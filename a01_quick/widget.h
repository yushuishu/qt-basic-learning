#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-17 23:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：窗口头文件
 * <p></p>
 */

QT_BEGIN_NAMESPACE
// 在此声明一个Widget类，这个类定义在 Ui 命名空间中
// 因为下面会定义一个 Ui::Widget 类型的指针 *ui
namespace Ui { class Widget; }
QT_END_NAMESPACE

// 我们自定义的 Widget 类，要继承自Qt框架提供的QWidget/QDialog/QMainWindow这三个类其中之一，才可以正常显示出来
// QWidget：基本的窗口组件，无任何内容，最纯白的窗口
// QMainWindow：是QWidget 的子类提供了一些高级窗口组件，如菜单栏、工具栏、状态栏和中央工作区等
// QDialog：对话框，执行短期任务，或者与用户进行互动，它可以是模态的，也可以是非模态的。QDialog窗口没有菜单栏、工具栏、状态栏等。
class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 定义一个 Ui::Widget 类型的指针 *ui
    // Ui::Widget 这个类定义在 ui_widget.h 中（可以 Ctrl+单击 跳转过去）
    // 这个 Ui::Widget 类，本身是空实现，但是它继承自 Ui_Widget 类

    // Ui_Widget 类，是和UI设计界面一一对应的，也就和widget.ui这个xml文件一一对应的
    // 至于为什么一个C++代码中类的对象，会和widget.ui这个xml文件一一对应
    Ui::Widget *ui;
};
#endif // WIDGET_H
