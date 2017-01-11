#include "wzsd.h"
#include "ui_wzsd.h"
long long num = 0;
long min = 0;
long max = 0;
WZSD::WZSD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WZSD)
{
    ui->setupUi(this);
    ui->showwin->addGraph();
    ui->showwin->addGraph();
    ui->showwin->legend->setVisible(true);
    ui->showwin->legend->setFont(QFont("Helvetica", 9));
    ui->showwin->graph(0)->setPen(QPen(Qt::blue));
    ui->showwin->graph(1)->setPen(QPen(Qt::red));
    ui->showwin->xAxis2->setVisible(true);
    ui->showwin->xAxis2->setTickLabels(false);
    ui->showwin->yAxis2->setVisible(true);
    ui->showwin->yAxis2->setTickLabels(false);

    ui->showwin->yAxis->setRange(-500,500);
    // make left and bottom axes always transfer their ranges to right and top axes:
    //connect(ui->showwin->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->showwin->xAxis2, SLOT(setRange(QCPRange)));
    //connect(ui->showwin->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->showwin->yAxis2, SLOT(setRange(QCPRange)));
    ui->showwin->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

}

WZSD::~WZSD()
{
    delete ui;
}

void WZSD::legendname(int n)
{
if(n == 0)
{
    ui->showwin->graph(0)->setName("WZ");
    ui->showwin->graph(1)->setName("SD");
}
else if(n == 1)
{
    ui->showwin->graph(0)->setName("Ia");
    ui->showwin->graph(1)->setName("Ib");
}
}

void WZSD::wzsdshow(long WZ,long SD)
{
  //QCustomPlot *customPlot = ui->showwin;
  num++;
  // add two new graphs and set their look:
  //customPlot->legend->setVisible(true);
  //customPlot->legend->setFont(QFont("Helvetica", 9));
  //customPlot->addGraph();
  //customPlot->graph(0)->setPen(QPen(Qt::blue)); // line color blue for first graph
 // customPlot->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20))); // first graph will be filled with translucent blue
  //customPlot->addGraph();
 // customPlot->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
  //customPlot->graph(0)->setName("WZ");
  //customPlot->graph(1)->setName("SD");
  // generate some points of data (y0 for first, y1 for second graph):
 // QVector<double> x(251), y0(251), y1(251);
  // configure right and top axis to show ticks but no labels:
  // (see QCPAxisRect::setupFullAxesBox for a quicker method to do this)
  //customPlot->xAxis2->setVisible(true);
 // customPlot->xAxis2->setTickLabels(false);
 // customPlot->yAxis2->setVisible(true);
  //customPlot->yAxis2->setTickLabels(false);
  // make left and bottom axes always transfer their ranges to right and top axes:
  //connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
  //connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));
  // pass data points to graphs:
  ui->showwin->graph(0)->addData(num,WZ);
  ui->showwin->graph(1)->addData(num,SD);
  ui->showwin->replot();
  /*if(WZ>max || SD>max)
  {
      max = WZ>SD? WZ:SD;
  }
  if(WZ<min || SD<min)
  {
      min = WZ>SD? SD:WZ;
  }
  customPlot->yAxis->setRange(min-500,max+500);*/
  // let the ranges scale themselves so graph 0 fits perfectly in the visible area:
  ui->showwin->graph(0)->rescaleAxes();
  // same thing for graph 1, but only enlarge ranges (in case graph 1 is smaller than graph 0):
  ui->showwin->graph(1)->rescaleAxes(true);
  // Note: we could have also just called customPlot->rescaleAxes(); instead
  // Allow user to drag axis ranges with mouse, zoom with mouse wheel and select graphs by clicking:
  //customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
}

void WZSD::saveplot(QString f)
{
    ui->showwin->saveJpg(f);

}

