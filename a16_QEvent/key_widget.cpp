#include "key_widget.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QKeyEvent>

/**
 * @Author ：谁书-ss
 * @Date ：2024-01-05 15:30
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：键盘事件
 * <p></p>
 */

KeyWidget::KeyWidget(QWidget *parent)
    : QWidget{parent} {
    QVBoxLayout *verticalLayout = new QVBoxLayout(this);
    verticalLayout->setSpacing(0);
    verticalLayout->setContentsMargins(0, 0, 0, 0);

    setFocusPolicy(Qt::StrongFocus);

    QLabel *lbl = new QLabel(this);
    lbl->setText("键盘事件");
    lbl->setFrameShape(QFrame::Box);
    lbl->setFixedHeight(50);
    lbl->setAlignment(Qt::AlignCenter);
    lbl->setStyleSheet("background-color: blue;color: white;font-size: 25px");
    verticalLayout->addWidget(lbl);

    lbl2 = new QLabel(this);
    lbl2->setText("");
    lbl2->setFrameShape(QFrame::Box);
    lbl2->setFixedSize(100, 100);
    lbl2->setStyleSheet("background-color: red");
}

void KeyWidget::keyPressEvent(QKeyEvent *keyEvent) {
    // 普通键
    switch (keyEvent->key() ) {
    case Qt::Key_Return:
        qDebug() << "Enter";
        break;
    case Qt::Key_Escape:
        qDebug() << "Esc";
        break;
    case Qt::Key_Control:
        qDebug() << "Ctrl";
        break;
    case Qt::Key_Shift:
        qDebug() << "Shift";
        break;
    case Qt::Key_Alt:
        qDebug() << "Alt";
        break;
    case Qt::Key_Up:
        qDebug() << "Up";
        break;
    case Qt::Key_Down:
        qDebug() << "Down";
        break;
    case Qt::Key_Left:
        qDebug() << "Left";
        break;
    case Qt::Key_Right:
        qDebug() << "Right";
        break;
    case Qt::Key_A:
        qDebug() << "A";
        break;
    case Qt::Key_B:
        qDebug() << "B";
        break;
    case Qt::Key_C:
        qDebug() << "C";
        break;
    case Qt::Key_D:
        qDebug() << "D";
        break;
    default:
        break;
    }

    switch (keyEvent->key() ) {
    case Qt::Key_Up:
        qDebug() << "Up";
        lbl2->move(lbl2->x(), lbl2->y() - 20);
        if (lbl2->y() + lbl2->height() <= 0 ) {
            lbl2->move(lbl2->x(), this->height());
        }
        break;
    case Qt::Key_Down:
        qDebug() << "Down";
        lbl2->move(lbl2->x(), lbl2->y() + 20);
        if (lbl2->y() >= this->height() ) {
            lbl2->move(lbl2->x(), 0);
        }
        break;
    case Qt::Key_Left:
        qDebug() << "Left";
        lbl2->move(lbl2->x() - 20, lbl2->y());
        if (lbl2->x() + lbl2->width() <= 0 ) {
            lbl2->move(this->width(), lbl2->y());
        }
        break;
    case Qt::Key_Right:
        qDebug() << "Right";
        lbl2->move(lbl2->x() + 20, lbl2->y());
        if (lbl2->x() >= this->width() ) {
            lbl2->move(0, lbl2->y());
        }
        break;
    }

    // 两键组合
    //    qDebug() << event->modifiers(); // QFlags<Qt::KeyboardModifier>(ShiftModifier|ControlModifier)
    // event->modifiers()，用来判读是否按下 Ctrl/Shift/Alt 键
    if ((keyEvent->modifiers() == Qt::ControlModifier) && (keyEvent->key() == Qt::Key_A) ) {
        qDebug() << "Ctrl + A";
    }
    if ((keyEvent->modifiers() == Qt::ShiftModifier) && (keyEvent->key() == Qt::Key_C) ) {
        qDebug() << "Shift + B";
    }
    if ((keyEvent->modifiers() == Qt::AltModifier) && (keyEvent->key() == Qt::Key_B) ) {
        qDebug() << "ALT + C";
    }
    // 三键组合Shift + Ctrl + D 的实现
    if ((keyEvent->modifiers() == (Qt::ShiftModifier | Qt::ControlModifier)) && (keyEvent->key() == Qt::Key_D) ) {
        qDebug() << "CTRL + Shift + D";
    }
}

void KeyWidget::keyReleaseEvent(QKeyEvent *keyEvent) {
    switch (keyEvent->key()) {
    case Qt::Key_Return:
        qDebug() << "keyReleaseEvent: Enter";
        break;
    case Qt::Key_Escape:
        qDebug() << "keyReleaseEvent: Esc";
        break;
    case Qt::Key_Up:
        qDebug() << "keyReleaseEvent: Up";
        break;
    case Qt::Key_Down:
        qDebug() << "keyReleaseEvent: Down";
        break;
    case Qt::Key_Left:
        qDebug() << "keyReleaseEvent: Left";
        break;
    case Qt::Key_Right:
        qDebug() << "keyReleaseEvent: Right";
        break;
    case Qt::Key_A:
        qDebug() << "keyReleaseEvent: A";
        break;
    case Qt::Key_B:
        qDebug() << "keyReleaseEvent: B";
        break;
    case Qt::Key_C:
        qDebug() << "keyReleaseEvent: C";
        break;
    case Qt::Key_D:
        qDebug() << "keyReleaseEvent: D";
        break;
    case Qt::Key_Control:
        qDebug() << "keyReleaseEvent: Ctrl";
        break;
    case Qt::Key_Shift:
        qDebug() << "keyReleaseEvent: Shift";
        break;
    case Qt::Key_Alt:
        qDebug() << "keyReleaseEvent: Alt";
        break;
    }
}
