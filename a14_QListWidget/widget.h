#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidgetItem>
#include <QButtonGroup>

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-08 08:27
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private slots:
    void rbModeClicked();
    void onItemClicked(QListWidgetItem *item);
    void onItemDoubleClicked(QListWidgetItem *item);
    void onBtnAddClicked();
    void onBtnInsertClicked();
    void onBtnDeleteClicked();
private:
    Ui::Widget *ui;

    QButtonGroup * operateButtonGroup;
};
#endif // WIDGET_H
