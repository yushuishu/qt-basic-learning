#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-07 10:39
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
    void hsRedChanged(int value);
    void hsGreenChanged(int value);
    void hsBlueChanged(int value);
    void leRedResultChanged(const QString &arg1);
    void leGreenResultChanged(const QString &arg1);
    void leBlueResultChanged(const QString &arg1);

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
