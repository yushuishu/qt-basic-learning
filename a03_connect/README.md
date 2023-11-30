# a03_connect

## 学习内容

信号和槽要建立连接，本质上是通过 `connect` 函数来连接实现的。但是从写法或者操作上来说，有多种方式，以下总结了 5 种方式：
- SIGNAL/SLOT（Qt4）
- 函数地址（Qt5）
- UI 设计师界面 - 转到槽
- UI 设计师界面 - 信号槽编辑器
- lambda 表达式


## SIGNAL/SLOT（Qt4）
SIGNAL/SLOT（Qt4） 这两个宏，将函数名以及对应的参数，转换为字符串，这是 Qt4 中使用的方式

格式：`connect(sender, SIGNAL(signal()), receiver, SLOT(slot()));`

这种方式，编译器不会做错误检查，即使函数名或者参数写错了，也可以编译通过，这样就把问题留在了运行阶段。

比如：`connect(ui->btnMax, SIGNAL(clicked()), this, SLOT(showMaximized()));`

如果 showMaximized 不小心写成了 showMaximize，点击【构建】菜单->【重新构建】，在【编译输出】窗口并不会报错，而在运行时报错

不推荐使用这种方式：https://github.com/KDE/clazy/blob/1.11/docs/checks/README-connect-by-name.md

## 函数地址（Qt5）
函数地址（Qt5），这种方式，编译时就会对函数类型，参数个数做检查。

格式：`connect(sender, &Sender::signal, receiver, &Receiver::slot);`
- sender：信号发送者
- &Sender::signal：发送的信号
- receiver：信号接收者
- &Receiver::slot：槽函数

比如：`connect(ui->btnNormal, &QPushButton::clicked, this, &QWidget::showNormal);`


## UI设计师界面-鼠标右键，转到槽
在 UI 设计师界面，右键单击 btnMin，然后选择【转到槽…】，弹出窗口，选择 clicked()即可生成并跳转到槽函数，即可在 widget.h 和 widget.cpp 中生成对应的代码，此时会根据按钮的 name 自动生成对应的槽函数

不推荐使用这种方式：https://github.com/KDE/clazy/blob/1.11/docs/checks/README-connect-by-name.md

## UI设计师界面-信号槽编辑器
使用这种方式，实现点击 btnClose 按钮，关闭窗口。

进入到 UI 设计师界面，【View】菜单 ->【视图】->【Signal & Slots Editor】，在打开的信号槽编辑器中，点击绿色的加号+ 就可以连接信号和槽了：

不推荐使用这种方式：https://github.com/KDE/clazy/blob/1.11/docs/checks/README-connect-by-name.md

## Lambda 表达式
修改窗口的标题
```c++
connect(ui->btnSetTitle, &QPushButton::clicked, this, [this]() {
    this->setWindowTitle("[连接信号槽的 5 种方式]");
});
```

## 使用总结

推荐使用`函数地址（Qt5）` 和 lambda 表达式。

connect()连接使用方式在Qt6中变化不大，与Qt5的使用方式一致

- SIGNAL/SLOT（Qt4）
  传统的使用方式，传递的是信号和槽函数的字符串名称，编译时不检查类型和参数，运行时容易出错
- 函数地址（Qt5）<font color="#dd0000">（强烈推荐使用）</font>
  语法简洁，易于阅读；
  没有字符串转换的开销；
  编译时的类型检查，使得连接安全性得到增强；
- UI 设计师界面 - 转到槽
  灵活性不如代码，复杂页面需要通过代码实现；
  如果使用其它ide开发，可能出现问题；
  运行时动态创建和销毁的 UI 元素，使用UI界面设计，会比较困难。
- UI 设计师界面 - 信号槽编辑器
  灵活性不如代码，复杂页面需要通过代码实现；
  如果使用其它ide开发，可能出现问题；
  运行时动态创建和销毁的 UI 元素，使用UI界面设计，会比较困难。
- lambda 表达式<font color="#dd0000">（强烈推荐使用）</font>
  语法简洁，易于阅读；
  没有字符串转换的开销；
  编译时的类型检查，使得连接安全性得到增强；
  可以直接在connect的地方定义一段处理逻辑，特别适合处理简单的，不值得单独定义槽函数的逻辑
