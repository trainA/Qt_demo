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
    //创建一个绘图区
    ui->customPlot->addGraph();
    //向某一个添加数据
    ui->customPlot->graph(0)->setData(datX, datY);
    //设置两个轴上显示的标签
    ui->customPlot->xAxis->setLabel(titleX);
    ui->customPlot->yAxis->setLabel(titleY);
    //设置自动确定边界
    ui->customPlot->graph(0)->rescaleAxes(true);

   ui->customPlot->graph(0)->setName("Confidence Band 68%");
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

void ChartPlot::CreateHistogram()
{
    // set dark background gradient:
    QLinearGradient gradient(0, 0, 0, 400);//渐变色
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->customPlot->setBackground(QBrush(gradient));//设置全局背景颜色

    // create empty bar chart objects:
    //创建3个图表对象
    QCPBars *regen = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *nuclear = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    QCPBars *fossil = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
    regen->setAntialiased(false); // 去锯齿
    nuclear->setAntialiased(false);
    fossil->setAntialiased(false);
    regen->setStackingGap(1);//每个数据隔开一点距离
    nuclear->setStackingGap(1);
    fossil->setStackingGap(1);
    // 设置每个图表的颜色 和名字
    fossil->setName("Fossil fuels");
    fossil->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    fossil->setBrush(QColor(111, 9, 176));
    nuclear->setName("Nuclear");
    nuclear->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    nuclear->setBrush(QColor(250, 170, 20));
    regen->setName("Regenerative");
    regen->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    regen->setBrush(QColor(0, 168, 140));
    // stack bars on top of each other:
    //将图表移动到另一个上面 这里设置成了三个在一个上面
    nuclear->moveAbove(fossil);
    regen->moveAbove(nuclear);

    // prepare x axis with country labels:
    QVector<double> ticks;
    QVector<QString> labels;
    ticks << 1 << 2 << 3 << 4 << 5 << 6 << 7;
    labels << "USA" << "Japan" << "Germany" << "France" << "UK" << "Italy" << "Canada";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, labels);
    ui->customPlot->xAxis->setTicker(textTicker);//设置的内容
    ui->customPlot->xAxis->setTickLabelRotation(60);//显示倾斜角度
    ui->customPlot->xAxis->setSubTicks(false);
    ui->customPlot->xAxis->setTickLength(0, 4);
    ui->customPlot->xAxis->setRange(0, 8);
    ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->xAxis->grid()->setVisible(true);
    ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->customPlot->xAxis->setTickLabelColor(Qt::white);
    ui->customPlot->xAxis->setLabelColor(Qt::white);

    // prepare y axis:
    ui->customPlot->yAxis->setRange(0, 12.1);
    ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
    ui->customPlot->yAxis->setLabel("Power Consumption in\nKilowatts per Capita (2007)");
    ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
    ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->customPlot->yAxis->grid()->setSubGridVisible(true);
    ui->customPlot->yAxis->setTickLabelColor(Qt::white);
    ui->customPlot->yAxis->setLabelColor(Qt::white);
    ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // Add data:
    QVector<double> fossilData, nuclearData, regenData;
    fossilData  << 0.86*10.5 << 0.83*5.5 << 0.84*5.5 << 0.52*5.8 << 0.89*5.2 << 0.90*4.2 << 0.67*11.2;
    nuclearData << 0.08*10.5 << 0.12*5.5 << 0.12*5.5 << 0.40*5.8 << 0.09*5.2 << 0.00*4.2 << 0.07*11.2;
    regenData   << 0.06*10.5 << 0.05*5.5 << 0.04*5.5 << 0.06*5.8 << 0.02*5.2 << 0.07*4.2 << 0.25*11.2;
    fossil->setData(ticks, fossilData);
    nuclear->setData(ticks, nuclearData);
    regen->setData(ticks, regenData);

    // setup legend:
    ui->customPlot->legend->setVisible(true);
    ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->customPlot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->customPlot->legend->setFont(legendFont);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
}
