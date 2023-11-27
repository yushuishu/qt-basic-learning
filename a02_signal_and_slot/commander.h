#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-18 13:07
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */


// 1、自定义的类，需要继承自 QObject类
class Commander : public QObject
{
    // 2、添加 Q_OBJECT 宏，才能正常使用Qt 的信号和槽机制
    Q_OBJECT
public:
    explicit Commander(QObject *parent = nullptr);

// 3、在signals 后面添加自定义的信号即可
signals:
    // （1）、信号只需声明，无需实现 （2）、信号返回值为 void
    void go();
    void go(QString);
};

#endif // COMMANDER_H
