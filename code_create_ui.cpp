#include "code_create_ui.h"
#include "ui_code_create_ui.h"

code_create_ui::code_create_ui(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::code_create_ui)
{
    ui->setupUi(this);
}

code_create_ui::~code_create_ui()
{
    delete ui;
}
