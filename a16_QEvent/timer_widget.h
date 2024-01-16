#ifndef TIMERWIDGET_H
#define TIMERWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QTimer>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:31
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：定时器事件
 * <p></p>
 */

class TimerWidget : public QWidget {
    Q_OBJECT
public:
    explicit TimerWidget(QWidget *parent = nullptr);
private:
    QLabel *lbl1;
    QLabel *lbl2;
    int id1;
    int id2;

    QTimer *timer1;
    QTimer *timer2;


protected:
    void timerEvent(QTimerEvent *event);


private slots:
    void onStartClicked();
    void onStopClicked();
    void onResetClicked();

    void onTimeout1();
    void onTimeout2();


signals:
};

#endif // TIMERWIDGET_H
