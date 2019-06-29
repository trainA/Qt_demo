#ifndef CODE_CREATE_UI_H
#define CODE_CREATE_UI_H

#include <QDialog>

namespace Ui {
class code_create_ui;
}

class code_create_ui : public QDialog
{
    Q_OBJECT

public:
    explicit code_create_ui(QWidget *parent = 0);
    ~code_create_ui();

private:
    Ui::code_create_ui *ui;
};

#endif // CODE_CREATE_UI_H
