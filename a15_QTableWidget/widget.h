#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QTableWidgetItem>

/**
 * @Author ：谁书-ss
 * @Date ：2023-12-12 08:49
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
    void appendOneRow(QString name, QString gender, int age, QString province);
private:
    Ui::Widget *ui;
    QButtonGroup *mButtonGroupSelection;
private slots:
    void btnStyleSheetClicked();
    void onSelectionRadioButtonClicked();
    void onItemClicked(QTableWidgetItem *item);
    void insertOneRow(int row, QString name, QString gender, int age, QString province);
    void btnAppendClicked();
    void btnInsertClicked();
    void btnDeleteClicked();
    void btnModifyClicked();
};
#endif // WIDGET_H
