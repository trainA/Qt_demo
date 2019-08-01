#include "dialog_text_edit.h"
#include "ui_dialog_text_edit.h"

dialog_text_edit::dialog_text_edit(QWidget *parent)
        : QDialog(parent),ui(new Ui::dialog_text_edit)
{
    ui->setupUi(this);
//    ui->plainTextEdit->appendPlainText(QString("xxx"));//添加文字
    connect(ui->rb_black,SIGNAL(clicked()),this,SLOT(set_font_color()));//自定义槽函数绑定 注意 set_font_color 在头文件里定义了
    connect(ui->rb_blue,SIGNAL(clicked()),this,SLOT(set_font_color()));
    connect(ui->rb_red,SIGNAL(clicked()),this,SLOT(set_font_color()));
    ui->rb_black->setChecked(true);
}
dialog_text_edit::~dialog_text_edit()
{

}



void dialog_text_edit::on_checkBox_3_clicked(bool checked)//这里checked 带着单选框的选择状态传入，如果没有选择带参数的则需要在函数内部判断
{
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked); //设置是否添加下划线
    //同样的看选择加粗 倾斜等
    ui->plainTextEdit->setFont(font); //将格式应用到界面上的编辑框里
}

void dialog_text_edit::set_font_color()
{
    QPalette plet = ui->plainTextEdit->palette();
    if(ui->rb_black->isChecked())
        plet.setColor(QPalette::Text,Qt::black);
    else if(ui->rb_blue->isChecked())
        plet.setColor(QPalette::Text,Qt::blue);
    else if(ui->rb_red->isChecked())
        plet.setColor(QPalette::Text,Qt::red);
    ui->plainTextEdit->setPalette(plet);
}

void dialog_text_edit::on_but_close_clicked()
{

}
