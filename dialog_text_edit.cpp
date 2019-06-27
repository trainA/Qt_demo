#include "dialog_text_edit.h"
#include "ui_dialog_text_edit.h"

dialog_text_edit::dialog_text_edit(QWidget *parent)
        : QDialog(parent),ui(new Ui::dialog_text_edit)
{
    ui->setupUi(this);
    ui->plainTextEdit->appendPlainText(QString("xxx"));
}
dialog_text_edit::~dialog_text_edit()
{

}

