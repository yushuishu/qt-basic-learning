#ifndef PROPAGATELABEL_H
#define PROPAGATELABEL_H

#include <QLabel>


/**
 * @Author ：谁书-ss
 * @Date ：2024-03-06 16:37
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

class PropagateLabel : public QLabel {
    Q_OBJECT
public:
    explicit PropagateLabel(QWidget *parent = nullptr);
private:
    void mousePressEvent(QMouseEvent* event);
    bool event(QEvent* e);
signals:
};

#endif // PROPAGATELABEL_H
