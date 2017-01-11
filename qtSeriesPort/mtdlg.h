#ifndef MTDLG_H
#define MTDLG_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class mtDlg;
}

class mtDlg : public QDialog
{
    Q_OBJECT

public:
    int n;
    double tempnum[10];
    explicit mtDlg(QWidget *parent = 0);
    ~mtDlg();
    void setupRealtimeDataDemo(QCustomPlot *customPlot);
public slots:
  void realtimeDataSlot(long WZ,long SD,int i);



private slots:
  void on_pushButton_clicked();

  void on_butShowWZSD_clicked();

  void on_butShowIaIb_clicked();

private:
    Ui::mtDlg *ui;
    QString demoName;
    QTimer dataTimer;
    QCPItemTracer *itemDemoPhaseTracer;
    int currentDemoIndex;
};

#endif // MTDLG_H
