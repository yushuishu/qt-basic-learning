#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-03 17:09
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
    void btnGetSelectionClicked();
    void onRadioButtonClicked();
    void cbAllClicked();
    void onStateChanged();

private:
    Ui::Widget *ui;
    QButtonGroup* buttonGroup;
    QButtonGroup* buttonGroup2;
};
#endif // WIDGET_H
