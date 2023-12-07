#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "QTimer"
#include "QMessageBox"

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-07 14:22
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void btnFileDownload();
    void btnFileCopy();
    void onFileDownloadTimeout();
    void onFileCopyTimeout();


private:
    Ui::Widget *ui;

    QTimer *mTimerFileDownload;
    QTimer *mTimerFileCopy;

};
#endif // WIDGET_H
