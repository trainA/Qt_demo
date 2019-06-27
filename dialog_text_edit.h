#ifndef DIALOG_TEXT_EDIT_H
#define DIALOG_TEXT_EDIT_H
//新建好文件需要确定好对应UI文件的objectname 和类名是一样的如果不是的话将会编译错误 如果不使用可视化界面创建UI可以忽略
#include <QDialog>
namespace Ui {
    class dialog_text_edit ;
}

class dialog_text_edit :public QDialog
{
    Q_OBJECT
public:

  explicit dialog_text_edit(QWidget *parent = 0);//这个关键字控制构造函数不会隐式的转换
    ~dialog_text_edit();
private :
   Ui::dialog_text_edit *ui;
};

#endif // DIALOG_TEXT_EDIT_H
