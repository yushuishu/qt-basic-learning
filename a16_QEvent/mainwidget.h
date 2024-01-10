#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QStackedWidget>
// 为了把多个 QPushButton 统一管理并实现互斥，放到一个 QButtonGroup 中
#include <QButtonGroup>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 13:55
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
private:
    QWidget *navWidget;
    QWidget *mainWidget;
    QStackedWidget * stackedWidget;

    void initNav();
    QButtonGroup* btnGroup;

    void initMain();

private slots:
    void btnClicked();
};

#endif // MAINWIDGET_H
