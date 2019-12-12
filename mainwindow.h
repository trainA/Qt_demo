#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();


    void on_but_massage_clicked();

    void on_pb_code_creatUI_clicked();

private:
    void dynamic_add_module();
    void dynamic_add_statusBar();
private:
    Ui::MainWindow *ui;
    QTextEdit *mTextEdit;
    QDockWidget *mDock;
};

#endif // MAINWINDOW_H
