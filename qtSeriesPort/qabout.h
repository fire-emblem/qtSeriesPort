#ifndef QABOUT_H
#define QABOUT_H

#include <QDialog>
#include <QPainter>
namespace Ui {
class qAbout;
}

class qAbout : public QDialog
{
    Q_OBJECT

public:
    explicit qAbout(QWidget *parent = 0);
    ~qAbout();

private:
    Ui::qAbout *ui;
    void paintEvent(QPaintEvent *);
};

#endif // QABOUT_H
