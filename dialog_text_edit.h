#ifndef DIALOG_TEXT_EDIT_H
#define DIALOG_TEXT_EDIT_H
#include <QDialog>
namespace UI {
    class dialog_text_edit ;
}

class dialog_text_edit :public QDialog
{
    Q_OBJECT
public:
  explicit Dialog(QWidget *parent = 0);//这个关键字控制构造函数不会隐式的转换
    ~dialog_text_edit();
private :
    UI::dialog_text_edit *ui;

};

#endif // DIALOG_TEXT_EDIT_H
