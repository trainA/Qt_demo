#include "chartplot.h"
#include "ui_chartplot.h"

ChartPlot::ChartPlot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartPlot)
{
    ui->setupUi(this);
}

ChartPlot::~ChartPlot()
{
    delete ui;
}
