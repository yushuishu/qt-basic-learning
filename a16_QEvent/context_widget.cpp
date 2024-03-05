#include "context_widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:34
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：右键菜单
 * <p></p>
 */

ContextWidget::ContextWidget(QWidget *parent)
    : QWidget{parent} {

    cut = new QAction("剪切(T)", this);
    copy = new QAction("复制(C)", this);
    paste = new QAction("粘贴(P)", this);
    toUpper = new QAction("转成大写(U)", this);
    toLower = new QAction("转成小写(L)", this);
    hide = new QAction("隐藏行", this);

    connect(cut, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(copy, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(paste, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(toUpper, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(toLower, SIGNAL(triggered()), this, SLOT(slotAction()));
    connect(hide, SIGNAL(triggered()), this, SLOT(slotAction()));
}

void ContextWidget::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu* menu = new QMenu();

    //菜单栏显示宽度
    menu->setFixedWidth(160);
    menu->addAction(cut);
    menu->addAction(copy);
    menu->addAction(paste);
    menu->addSeparator();
    menu->addAction(toUpper);
    menu->addAction(toLower);
    menu->addSeparator();
    menu->addAction(hide);

    menu->exec(event->globalPos());

    delete menu;
}

void ContextWidget::slotAction()
{
    QAction *act = (QAction*)(sender());
#if 0
    if(act == cut) {
        qDebug() << "clot_cut";
    }
#endif
    qDebug() << act->text();
}
