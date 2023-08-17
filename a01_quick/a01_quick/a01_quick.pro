# 添加用到的QT，模块，比如要使用数据库，就需要添加SQL模块
# core：核心模块，提供了信号与槽的通信机制，并发和多线程，容器，事件系统
# gui：最重要的GUI模块。图形用户界面 (GUI) 组件的基类。
QT       += core gui

# 如果使用QT版本大于QT4，需要添加widgets 模块，
# 因为在QT5之后，就将widgets 从gui 模块中独立出来了，窗口程序开发必须包含widgets 模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# 使用c++17 新特性
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# 指定源文件
SOURCES += \
    main.cpp \
    widget.cpp

# 指定头文件
HEADERS += \
    widget.h

# 指定ui文件
FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
