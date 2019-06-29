#ifndef UNIVERSAL_HEAD_H
#define UNIVERSAL_HEAD_H
/*
这个头文件里包含了一些常用的头文件避免平时头文件浪费时间
*/
#include <QDebug>
#include <QString>

#ifndef NOT_CREATE_UI
    #include <QCheckBox>
    #include <QPushButton>
    #include <QRadioButton>
    #include <QPlainTextEdit>
    #include <QHBoxLayout>

#endif

#ifndef NOT_INPUT_QSTL
    #include <QList>
    #include <QVector>
    #include <QMap>
    #include <QSet>
    #include <QStringList>
#endif

#endif // UNIVERSAL_HEAD_H
