#include "qabout.h"
#include "ui_qabout.h"

qAbout::qAbout(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::qAbout)
{
    ui->setupUi(this);
    //this->setWindowFlags(Qt::FramelessWindowHint);//去掉标题栏
}

qAbout::~qAbout()
{
    delete ui;
}

void qAbout::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    //pix.load("C:\\Users\\admin\\Desktop\\qtSeriesPort\\qtSeriesPort\\image\\tj.png");
    pix.load("image\\tj.png");
    painter.drawPixmap(180,10,50,50,pix);
}
