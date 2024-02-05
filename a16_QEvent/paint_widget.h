#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QLabel>



/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:34
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：绘图事件
 * <p></p>
 */

class PaintWidget : public QWidget {
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);
private:
    QLabel *lblHigh;
    QLabel *lblLow;
    // 绘制高低温曲线
    void paintHigh();
    void paintLow();

private:
    int mHighTemp[7] = {0};
    int mLowTemp[7] = {0};

protected:
    bool eventFIlter(QObject *watched, QEvent *event);
signals:
};

#endif // PAINTWIDGET_H
