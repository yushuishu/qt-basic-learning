#ifndef KEYWIDGET_H
#define KEYWIDGET_H

#include <QWidget>
#include <QLabel>


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:30
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：键盘事件
 * <p></p>
 */

class KeyWidget : public QWidget {
    Q_OBJECT
public:
    explicit KeyWidget(QWidget *parent = nullptr);
private:
    QLabel *lbl2;
protected:
    // 按键按下
    void keyPressEvent(QKeyEvent *keyEvent);
    // 按键抬起
    void keyReleaseEvent(QKeyEvent *keyEvent);
signals:
};

#endif // KEYWIDGET_H
