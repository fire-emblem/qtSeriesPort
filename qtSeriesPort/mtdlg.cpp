#include "mtdlg.h"
#include "ui_mtdlg.h"
#include <QTime>
#include <QTimer>
extern bool ShowEnable;
extern bool ShowSwitch;
mtDlg::mtDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mtDlg)
{
    ui->setupUi(this);

    setupRealtimeDataDemo(ui->qCustomPlot);


    ui->qCustomPlot->replot();

}

mtDlg::~mtDlg()
{
    delete ui;
}

void mtDlg::setupRealtimeDataDemo(QCustomPlot *customPlot)
{
  //demoName = "Real Time Data Demo";

  // include this section to fully disable antialiasing for higher performance:
  /*
  customPlot->setNotAntialiasedElements(QCP::aeAll);
  QFont font;
  font.setStyleStrategy(QFont::NoAntialias);
  customPlot->xAxis->setTickLabelFont(font);
  customPlot->yAxis->setTickLabelFont(font);
  customPlot->legend->setFont(font);
  */

  customPlot->legend->setVisible(true);
  customPlot->legend->setFont(QFont("Helvetica", 9));

  customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes |
                                       QCP::iSelectLegend | QCP::iSelectPlottables);
  customPlot->addGraph(); // blue line
  customPlot->graph(0)->setPen(QPen(QColor(40, 110, 255)));
  //customPlot->graph(0)->setName("WZ");
  customPlot->addGraph(); // red line
  customPlot->graph(1)->setPen(QPen(QColor(255, 110, 40)));
  //customPlot->graph(1)->setName("SD");

  QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
  timeTicker->setTimeFormat("%h:%m:%s");
  customPlot->xAxis->setTicker(timeTicker);
  customPlot->axisRect()->setupFullAxesBox();
  customPlot->yAxis->setRange(-10000, 10000);

  // make left and bottom axes transfer their ranges to right and top axes:
 // connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
 // connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

  // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
  //connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
 // dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}


void mtDlg::realtimeDataSlot(long WZ,long SD,int i)
{
    if(i == 0)
    {
        ui->qCustomPlot->graph(0)->setName("WZ");
        ui->qCustomPlot->graph(1)->setName("SD");
    }
    else if(i == 1)
    {
        ui->qCustomPlot->graph(0)->setName("Ia");
        ui->qCustomPlot->graph(1)->setName("Ib");
    }

  static QTime time(QTime::currentTime());
  // calculate two new data points:
  dataTimer.start(0);
  double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
  static double lastPointKey = 0;
  if (key-lastPointKey > 0.1) // at most add point every 2 ms
  {
    // add data to lines:
    //ui->customPlot->graph(0)->addData(key, qSin(key)/*+qrand()*//(double)RAND_MAX*1*qSin(key/0.3843));
    //ui->customPlot->graph(1)->addData(key, qCos(key)/*+qrand()*//(double)RAND_MAX*0.5*qSin(key/0.4364));
      ui->qCustomPlot->graph(0)->addData(key, WZ);
      ui->qCustomPlot->graph(1)->addData(key, SD);
     // if(i<10) i += 1; else i = 0;
     // if(j>0) j -= 1; else j = 10;
    // rescale value (vertical) axis to fit the current data:
    //ui->customPlot->graph(0)->rescaleValueAxis();
    //ui->customPlot->graph(1)->rescaleValueAxis(true);
    lastPointKey = key;
  }
  // make key axis range scroll with the data (at a constant range size of 8):
  ui->qCustomPlot->xAxis->setRange(key, 8, Qt::AlignRight);
  ui->qCustomPlot->replot();

  // calculate frames per second:
  static double lastFpsKey;
  static int frameCount;
  ++frameCount;
  if (key-lastFpsKey > 2) // average fps over 2 seconds
  {
    /*ui->statusBar->showMessage(
          QString("%1 FPS, Total Data points: %2")
          .arg(frameCount/(key-lastFpsKey), 0, 'f', 0)
          .arg(ui->qCustomPlot->graph(0)->data()->size()+ui->customPlot->graph(1)->data()->size())
          , 0);*/
    lastFpsKey = key;
    frameCount = 0;
  }
}








void mtDlg::on_pushButton_clicked()
{
    ShowEnable = 0;

}

void mtDlg::on_butShowWZSD_clicked()
{
    ShowSwitch = 0;
}

void mtDlg::on_butShowIaIb_clicked()
{
    ShowSwitch = 1;
}
