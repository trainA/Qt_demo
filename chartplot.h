#ifndef CHARTPLOT_H
#define CHARTPLOT_H

#include <QDialog>

namespace Ui {
class ChartPlot;
}

class ChartPlot : public QDialog
{
    Q_OBJECT

public:
    explicit ChartPlot(QWidget *parent = 0);
    ~ChartPlot();

private:
    Ui::ChartPlot *ui;
};

#endif // CHARTPLOT_H
