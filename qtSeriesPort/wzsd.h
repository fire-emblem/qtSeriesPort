#ifndef WZSD_H
#define WZSD_H

#include <QDialog>
#include "qcustomplot.h"

namespace Ui {
class WZSD;
}

class WZSD : public QDialog
{
    Q_OBJECT

public:
    explicit WZSD(QWidget *parent = 0);
    void wzsdshow(long WZ,long SD);
    void saveplot(QString f);
    void legendname(int n);
    ~WZSD();

private:
    Ui::WZSD *ui;
};

#endif // WZSD_H
