#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

/**
 * @Author ：谁书-ss
 * @Date ：2023-11-30 12:55
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
    void startStopButton();
    void connectButton();
    void signalButtonClicked();
    void signalButtonPressed();
    void signalButtonReleased();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
