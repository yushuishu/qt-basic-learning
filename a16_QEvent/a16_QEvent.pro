QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    context_widget.cpp \
    drag_widget.cpp \
    enter_leave_widget.cpp \
    key_widget.cpp \
    labelx.cpp \
    main.cpp \
    mainwidget.cpp \
    paint_widget.cpp \
    press_move_release_widget.cpp \
    propagate_widget.cpp \
    propagatelabel.cpp \
    texteditx.cpp \
    timer_widget.cpp

HEADERS += \
    context_widget.h \
    drag_widget.h \
    enter_leave_widget.h \
    key_widget.h \
    labelx.h \
    mainwidget.h \
    paint_widget.h \
    press_move_release_widget.h \
    propagate_widget.h \
    propagatelabel.h \
    texteditx.h \
    timer_widget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
