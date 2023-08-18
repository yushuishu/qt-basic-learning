# a02_signal_and_slot

## 学习内容

信号和槽（标准信号槽 和 自定义信号槽）


## 标准信号槽

ui拖放按钮，分别是btnMax，btnNormal，btnMin，btnClose

widget.cpp 中设置按钮文本
```c++
ui->btnMax->setText("最大化显示");
ui->btnNormal->setText("正常显示");
ui->btnMin->setText("最小化");
ui->btnClose->setText("关闭窗口");
```

函数 connect() 用于连接`信号`和`槽`

函数格式：`connect(sender, signal, receiver, slot)`
- sender: 发出信号的对象，比如 QpushButton 按钮
- signal: 发出的信号，比如 clicked() 点击操作
- receiver: 接收信号的对象，比如 QWidget 窗口
- slot: 接收信号之后，调用的函数

使用：
```c++
connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));
connect(ui->btnNormal, SIGNAL(clicked()), this, SLOT(showNormal()));
connect(ui->btnMin, SIGNAL(clicked()), this, SLOT(showMinimized()));
connect(ui->btnClose, SIGNAL(clicked()), this, SLOT(close()));
```

`showMaximized()`，`showNormal()`，`showMinimized()`，`close()` 均为Qt的标准函数


## 自定义信号槽

创建两个类的头文件和源文件，分别是commander.h（指挥官）和 soldier.h（士兵），都需要继承自 QObject类，添加 Q_OBJECT 宏，才能正常使用Qt 的信号和槽机制。

commander.h 声明两个go() 跑的方法，一个有参一个无参（测试信号方法可以重载）

soldier.h 声明两个fight() 战斗的方法，槽函数的返回值和参数，要和信号保持一致

soldier.cpp 实现两个fight()方法
```c++
void Soldier::fight() {
    std::cout << "fight" << std::endl;
}

void Soldier::fight(QString str) {
    std::cout << "fight for " << str.toStdString() <<std::endl;
}
```

创建两个实例
```c++
Commander commander;
Soldier soldier;
```

建立信号和槽的连接
```c++
connect(&commander, SIGNAL(go()), &soldier, SLOT(fight()));
connect(&commander, SIGNAL(go(Qstring)), &soldier, SLOT(fight(Qstring)));
```

发送信号
```c++
commander.go();
commander.go("freedom");
```


