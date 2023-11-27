#ifndef SOLDIER_H
#define SOLDIER_H

#include <QObject>
#include <iostream>
#include <string.h>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-18 13:07
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */


class Soldier : public QObject {
    Q_OBJECT
public:
    explicit Soldier(QObject *parent = nullptr);
signals:
// 1、通常将槽函数添加到 slots后面， 这个slots也可以不写，建议写上，以指明这是一个槽函数
// public 表示槽函数既可以在当前类及其子类的成员函数中调用，也可以在类外部的其它函数（比如main函数）中调用
public slots:
    // 2、槽函数的返回值和参数，要和信号保持一致
    //      由于信号无返回值，因此槽函数也无返回值
    //      由于信号无参数，因此槽函数也无参数
    void fight();
    void fight(QString);
};

#endif // SOLDIER_H
