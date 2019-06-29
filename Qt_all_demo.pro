#-------------------------------------------------
#
# Project created by QtCreator 2019-06-25T22:48:58
#
#-------------------------------------------------

QT       += core gui
#项目加入 core gui模块

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#条件执行语句，当qt版本 大于 4 的时候加入 widgets 模块


TARGET = Qt_all_demo
#目标文件可执行文件的文件名
TEMPLATE = app
#项目使用的模板是 app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS #

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#源文件
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog_text_edit.cpp \
    code_create_ui.cpp
#头文件
HEADERS += \
        mainwindow.h \
    dialog_text_edit.h \
    code_create_ui.h \
    universal_head.h
#窗体文件
FORMS += \
        mainwindow.ui \
    dialog_text_edit.ui \
    code_create_ui.ui
