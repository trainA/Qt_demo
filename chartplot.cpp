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

void ChartPlot::CreateLineChart(QVector<double> datX, QVector<double> datY,

                                QString titleX, QString titleY)
{
    ui->customPlot->addGraph();
    QPen pen;
    pen.setStyle(Qt::DotLine);
    pen.setWidth(1);
    pen.setColor(QColor(180,180,180));
    ui->customPlot->graph(0)->setName("Confidence Band 68%");
    ui->customPlot->graph(0)->setPen(pen);
    ui->customPlot->graph(0)->setBrush(QBrush(QColor(255,50,30,20)));


    //创建一个绘图区
    ui->customPlot->addGraph();
    //向某一个添加数据
    ui->customPlot->graph(1)->setData(datX, datY);
    //设置两个轴上显示的标签
    ui->customPlot->xAxis->setLabel(titleX);
    ui->customPlot->yAxis->setLabel(titleY);
    //设置自动确定边界
    ui->customPlot->graph(1)->rescaleAxes(true);

   ui->customPlot->graph(1)->setName("Confidence Band 68%");
    //设置两个轴线显示的范围
//    ui->customPlot->xAxis->setRange(xRange.first, xRange.second);
//    ui->customPlot->yAxis->setRange(yRange.first, yRange.second);
}

void ChartPlot::addLineChart(QVector<double> datX, QVector<double> datY,QPair<int,int>xRange,QPair<int,int>yRange)
{
    //创建一个绘图区
    ui->customPlot->addGraph();
    //向某一个添加数据
    ui->customPlot->graph(ui->customPlot->graphCount() - 1)->setData(datX, datY);

    //设置两个轴线显示的范围
    ui->customPlot->xAxis->setRange(xRange.first, xRange.second);
    ui->customPlot->yAxis->setRange(yRange.first, yRange.second);
}
