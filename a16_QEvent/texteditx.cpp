#include "texteditx.h"

#include <QDebug>
#include <QFile>
#include <QMimeData>
#include <QApplication>


/**
 * @Author ：谁书-ss
 * @Date ：2024-01-18 08:15
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

TextEditX::TextEditX(QWidget *parent)
    : QTextEdit{parent} {
    this->setAcceptDrops(true);
}

void TextEditX::dragEnterEvent(QDragEnterEvent *event) {
    qDebug() << "dragEnterEvent";

    // 判断是正常的文件，表明用户可以在这个窗口部件上拖放对象

    // 默认情况下，窗口部件是不接受拖动的，Qt会自动改变光标来向用户说明这个窗口部件是不是有效的放下点
    event->acceptProposedAction();
}

void TextEditX::dragMoveEvent(QDragMoveEvent *event) {
    qDebug() << "dragMoveEvent";
}

void TextEditX::dragLeaveEvent(QDragLeaveEvent *event) {
    qDebug() << "dragLeaveEvent";
}

void TextEditX::dropEvent(QDropEvent *event) {
    qDebug() << "dropEvent";

    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty()) {
        return;
    }
    QString fileName = urls.first().toLocalFile();

    qDebug() << urls.first() << "  :  " << fileName;

    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
        setPlainText(file.readAll());
    }
}

void TextEditX::wheelEvent(QWheelEvent *e) {
    // ctrl键的判断
    if (QApplication::keyboardModifiers() == Qt::ControlModifier) {
        qDebug() << "滚轮滚动大小：" << e->angleDelta().y();
        // zoomIn/zoomOut可以直接修改字体大小
        if (e->angleDelta().y() > 0) {
            // 滚轮远离使用者, 进行放大
            this->zoomIn();
        } else {
            // 进行缩小
            this->zoomOut();
        }
    } else {
        // 调用父类的，否则无法实现文本的上下滚动。
        QTextEdit::wheelEvent(e);
    }
}
