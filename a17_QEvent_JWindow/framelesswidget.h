#ifndef FRAMELESSWIDGET_H
#define FRAMELESSWIDGET_H

#include <QWidget>



/**
 * @Author ：谁书-ss
 * @Date ：2024-03-11 11:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

// 针对9个区域，定义了一个枚举变量；
enum Location {
    TOP,
    BOTTOM,
    LEFT,
    RIGHT,
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    CENTER
};

// 定义一个间距
#define PADDING 5

class FramelessWidget : public QWidget {
    Q_OBJECT

public:
    FramelessWidget(QWidget *parent = nullptr);
    ~FramelessWidget();
protected:
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mousePressEvent(QMouseEvent* event);
private:
    // 鼠标左键是否按下
    bool isLeftPressed;
    // 记录鼠标按下的位置
    QPoint mousePos;
    Location location;
    void setCursorShape(const QPoint& cursorPoint);
};
#endif // FRAMELESSWIDGET_H
