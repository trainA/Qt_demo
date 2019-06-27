#include <QMessageBox>
#include <QString>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_text_edit.h"
/*
QDebug()使用
%a,%A 读入一个浮点值(仅C99有效)
%c 读入一个字符
%d 读入十进制整数
%i 读入十进制，八进制，十六进制整数
%o 读入八进制整数
%x,%X 读入十六进制整数
%s 读入一个字符串，遇空格、制表符或换行符结束。
%f,%F,%e,%E,%g,%G 用来输入实数，可以用小数形式或指数形式输入。
%p 读入一个指针
%u 读入一个无符号十进制整数
%n 至此已读入值的等价字符数
%[] 扫描字符集合
%% 读%符号
qDebug("intensity:%d",intensity[0][2]); （%d表示整数）一个样例
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//实现窗口的生成与各种属性的设置

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    dialog_text_edit *t = new dialog_text_edit();
    t->show();
    //使用这个可能不会显示因为t 是在堆里面创建的 使用show（）的话当函数执行完成就释放掉
   // t.exec();//使用这个函数需要等到用户将对话框关闭才会消失
}


void MainWindow::on_but_massage_clicked()
{
    /*
    StandardButton QMessageBox::information(QWidget * parent, const QString & title, const QString & text, StandardButtons buttons = Ok, StandardButton defaultButton = NoButton) [static]
    第一个参数是父控件指针
    第二个参数是标题
    第三个参数是内容
    第四个参数是窗口里面要多少个按钮（默认为OK）
    第五个参数指定按下Enter时使用的按钮。（默认为NoButton，此时QMessageBox会自动选择合适的默认值。）
    +*/
    QMessageBox::information(NULL, "Title", "Content",
                             QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);


    QMessageBox:: StandardButton result = QMessageBox::information(NULL, "Title", "Content",QMessageBox::Yes|QMessageBox::No|
                                 QMessageBox::Abort);
    QString txt;
    switch (result)
    {
    case QMessageBox::Yes:
        qDebug()<<"Yes";
        txt = "yes";
        break;
    case QMessageBox::No:
        qDebug()<<"NO";
        txt = "NO";
        break;
    case QMessageBox::Abort :
        qDebug()<<"关于";
         txt = "关于";
        break;
    default:
        break;
    }
     QMessageBox::information(NULL, "Title", QString("用户单击的是:") + txt);
}
