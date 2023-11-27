#include "soldier.h"


/**
 * @Author ：谁书-ss
 * @Date ：2023-08-19 22:05
 * @IDE ：Qt Creator
 * @Motto ：ABC(Always Be Coding)
 * <p></p>
 * @Description ：
 * <p></p>
 */


Soldier::Soldier(QObject *parent)
    : QObject{parent}
{

}

void Soldier::fight()
{
    std::cout << "fight" << std::endl;
}
void Soldier::fight(QString str)
{
    std::cout << "fight for " << str.toStdString() << std::endl;
}
void Soldier::escape()
{
    std::cout << "i'm afraid of death, escape..." << std::endl;
}
