#ifndef CHARTPLOT_H
#define CHARTPLOT_H

#include <QDialog>
#include <QString>
#include <QPair>
namespace Ui {
class ChartPlot;
}

class ChartPlot : public QDialog
{
    Q_OBJECT

public:
    explicit ChartPlot(QWidget *parent = 0);
    ~ChartPlot();
    void CreateLineChart(QVector<double> datX, QVector<double> datY,
                         QString titleX= "", QString titleY = "");
    void addLineChart(QVector<double> datX, QVector<double> datY,QPair<int,int>xRange,QPair<int,int>yRange);
    void CreateHistogram();
private:
    Ui::ChartPlot *ui;
};

#endif // CHARTPLOT_H
