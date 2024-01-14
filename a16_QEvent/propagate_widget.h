#ifndef PROPAGATEWIDGET_H
#define PROPAGATEWIDGET_H

#include <QWidget>


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:35
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：总结：事件的传递流程
 * <p></p>
 */

class PropagateWidget : public QWidget {
    Q_OBJECT
public:
    explicit PropagateWidget(QWidget *parent = nullptr);

signals:
};

#endif // PROPAGATEWIDGET_H
