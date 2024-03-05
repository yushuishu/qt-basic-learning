#ifndef CONTEXTWIDGET_H
#define CONTEXTWIDGET_H

#include <QWidget>
#include <QContextMenuEvent>
#include <QMenu>
#include <QAction>
#include <QCursor>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:34
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：右键菜单
 * <p></p>
 */

class ContextWidget : public QWidget {
    Q_OBJECT
public:
    explicit ContextWidget(QWidget *parent = nullptr);
private:
    QAction *cut;
    QAction *copy;
    QAction *paste;
    QAction *toUpper;
    QAction *toLower;
    QAction *hide;
protected:
    void contextMenuEvent(QContextMenuEvent *event);
private slots:
    void slotAction();
signals:
};

#endif // CONTEXTWIDGET_H
