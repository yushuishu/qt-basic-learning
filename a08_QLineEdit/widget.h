#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


/**
 * @Author ：谁书-ss
 * @Date ：2023-12-03 14:56
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
    // 回显模式
    void btnEchoNormal();
    void btnEchoPassword();
    void btnEchoNoEcho();
    void btnEchoPasswordEchoOnEdit();
    void btnEchoPrint();
    // 对齐方式
    void btnAlignLeft();
    void btnAlignCenter();
    void btnAlignRight();
    // 读写控制
    void btnAccessReadWrite();
    void btnAccessReadOnly();
    void btnAccessDisabled();
    void btnAccessEnabled();
    void btnAccessPrint();
    // 格式控制
    void btnMaskNone();
    void btnMaskPhone();
    void btnMaskLicense();
    // 信号槽
    void leAdd1_TextChanged(const QString &arg1);
    void leAdd2_TextChanged(const QString &arg1);
    void leSub1_EditingFinished();
    void leSub2_EditingFinished();


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
