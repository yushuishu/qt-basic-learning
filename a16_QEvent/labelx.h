#ifndef LABELX_H
#define LABELX_H

#include <QLabel>


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-11 22:18
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */


class LabelX : public QLabel {
    Q_OBJECT
public:
    explicit LabelX(QWidget *parent = nullptr);

protected:
    // 鼠标进入/离开事件
    void enterEvent(QEnterEvent *enterEvent);
    void leaveEvent(QEvent *event);
    // 鼠标按下、移动、释放事件
    void mousePressEvent(QMouseEvent *qmouseEvent);
    void mouseReleaseEvent(QMouseEvent *qmouseEvent);
    void mouseMoveEvent(QMouseEvent *qmouseEvent);
signals:
};

#endif // LABELX_H
