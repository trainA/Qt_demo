#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_text_edit.h"
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
    dialog_text_edit t;
    t.show();
}
