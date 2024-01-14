#ifndef PRESSMOVERELEASEWIDGET_H
#define PRESSMOVERELEASEWIDGET_H

#include <QWidget>
#include <QLabel>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:30
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：鼠标按下/移动/释放
 * <p></p>
 */

class PressMoveReleaseWidget : public QWidget {
    Q_OBJECT
public:
    explicit PressMoveReleaseWidget(QWidget *parent = nullptr);
private:
    QLabel *lbl;
    QWidget *widget;

    // 鼠标按下的位置
    QPointF localGlobalPosition;
    // 标签的位置（左上角的点top-left）
    QPoint wndPos;
protected:
    bool eventFilter(QObject *watched, QEvent *event);
signals:
};

#endif // PRESSMOVERELEASEWIDGET_H
