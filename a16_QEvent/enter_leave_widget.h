#ifndef ENTERLEAVEWIDGET_H
#define ENTERLEAVEWIDGET_H

#include <QWidget>
#include <QLabel>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:16
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：鼠标进入/离开
 * <p></p>
 */

class EnterLeaveWidget : public QWidget
{
    Q_OBJECT
public:
    explicit EnterLeaveWidget(QWidget *parent = nullptr);
private:
     QLabel* lbl;
protected:
     bool eventFilter(QObject* watched, QEvent* event);
signals:
};

#endif // ENTERLEAVEWIDGET_H
