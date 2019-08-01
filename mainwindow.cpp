#include <QMessageBox>
#include <QString>
#include <QDebug>
#include <QMenu>
#include <QAction>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_text_edit.h"
#include "code_create_ui.h"
#include "mainwindow.h"
#include "mainwindow.h"
#include "universal_head.h"
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

点击库函数按F1可以快速查看帮助文档
*/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//实现窗口的生成与各种属性的设置

    move(0,0);// move 是相当于屏幕位置

    dynamic_add_module();//动态添加菜单 按钮
    dynamic_add_statusBar();//动态添加状态栏
    QTextEdit *mTextEdit = new QTextEdit();
    mTextEdit->setText("设置核心控件");
    setCentralWidget(mTextEdit);//设置核心控件
    //浮动窗口
    QDockWidget *mDock = new QDockWidget();
    addDockWidget(Qt::RightDockWidgetArea,mDock);
    QTextEdit *mTextEditDock = new QTextEdit();
    mDock->setWidget(mTextEditDock);
}
MainWindow::~MainWindow()
{
    //所有继承QObject的类都会自动施放内存空间
    //或者指定了父对象的对象
    //Qt 有一个对象树 会从低到上进行遍历 释放内存空间
    delete ui;
}
void MainWindow::dynamic_add_module()
{

    //动态添加按钮
    QPushButton *btn_p1 = new QPushButton(this);//这里this 表示是 这个按钮的父窗口

    btn_p1->setText("Lamda表达式");
    //move总是对于他的父窗口而言
    btn_p1->move(200,100);
    btn_p1->resize(60,25);//设置按钮大小
    int ta = 10 , tb = 100;
    connect(btn_p1,&QPushButton::clicked,
         // 使用 = 将这里的全部局部传入（拷贝） 需要修改则需要在括号后面加上关键字 mutable
         //使用 & 将全部局部变量传入（不拷贝
         //输入某一个则传某一个值
            /*
            [] 什么也没有捕获
            [a, &b] 按值捕获a，按引用捕获b
            [&] 按引用捕获任何用到的外部变量
            [=] 按值捕获任何用到的外部变量
            [a, &] 按值捕获a, 其它的变量按引用捕获
            [&b, =] 按引用捕获b,其它的变量按值捕获
            [this] 按值捕获this指针
            如果不能使用则在 pro文件中加上 CONFIG += C++11
        */
        [&]() mutable
        {
             qDebug()<<"test";
             qDebug()<<ta<<tb;
            ta = 100,tb = 10;
        });
    //动态添加菜单栏及子项
    QMenuBar *mBar = menuBar();//菜单栏
    QMenu *pFile = mBar->addMenu("文件");//菜单
    QAction *pNew = pFile->addAction("新建");//菜单项
    //菜单项单击事件
    connect(pNew,&QAction::triggered,
            []()
                {
                      qDebug()<<tr("新建被按下");
                }
            );

    pFile->addSeparator();//添加分割线
    QAction *pOpen = pFile->addAction("打开");


    connect(pOpen,&QAction::triggered,
                []()
                {
                    qDebug()<<"打开被按下";
                }
            );

    QAction *p1 = mBar->addAction("模态对话框");
    connect(p1,&QAction::triggered,[=]()
                {
                       QDialog dlg;
                       dlg.exec();//这样 就不能操作父窗口
                       qDebug()<<"模态对话框";
                }
            );
    QAction *p2 = mBar->addAction("非模态对话框");
    connect(p2,&QAction::triggered,[=]()
                {
                    QDialog *dlg = new QDialog();
                    p2->set;
                }
            );
    QToolBar *mToolBar = addToolBar("toolBar");  //工具栏
    mToolBar->addAction(pNew);
    QPushButton *pBut = new QPushButton();
    pBut->setText("打开");
    mToolBar->addWidget(pBut);


}
//添加状态栏
void MainWindow::dynamic_add_statusBar()
{
    QStatusBar *mstatusbar = statusBar();
    QLabel *statusLabel = new QLabel(this);
    statusLabel->setText("无数据");
    mstatusbar->addWidget(statusLabel);
    mstatusbar->addPermanentWidget(new QLabel("这样就可以从右边添加",this));


}
//弹出对话框
void MainWindow::on_pushButton_clicked()
{
    dialog_text_edit *t = new dialog_text_edit();
    t->show();
    //使用这个可能不会显示因为t 是在堆里面创建的 使用show（）的话当函数执行完成就释放掉
   // t.exec();//使用这个函数需要等到用户将对话框关闭才会消失
}

//处理 信息框
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

void MainWindow::on_pb_code_creatUI_clicked()
{
    code_create_ui *t = new code_create_ui();
    t->show();
}
