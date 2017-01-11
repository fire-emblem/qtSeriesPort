#ifndef THREAD_H
#define THREAD_H
#include <QObject>
#include <QThread>
#include <QFileDialog>
#include "wzsd.h"
#include "qcustomplot.h"
class WZSDThread : public QThread
{
   Q_OBJECT
public:
   WZSDThread(QObject *parent = 0)
       : QThread(parent)
   {
       moveToThread(this);
   }

   QString filename;
   WZSD showwzsd;
   void getname(QString a)
   {
       filename = a;
   }


protected:
   void run()
   {
       bool ok;
       long WZ,SD;
       //WZSD showwzsd;
       //WorkerThread *thread = new WorkerThread(this);
       showwzsd.legendname(0);

       QFile WZin(filename+"\\WZ.txt");
       qDebug()<<filename+"\\WZ.txt"<<endl;
       if(!WZin.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug()<<"Can't open the file!"<<endl;
       }

       QFile SDin(filename+"\\SD.txt");
       if(!SDin.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug()<<"Can't open the file!"<<endl;
       }
       while(!WZin.atEnd()) {

           QByteArray line = WZin.readLine();
           QString str(line);
           WZ = str.toLong(&ok,10);

           line = SDin.readLine();
           QString str1(line);
           SD = str1.toLong(&ok,10);
           qDebug()<<WZ<<endl;
           showwzsd.wzsdshow(WZ,SD);


       }
       //showwzsd.show();
       showwzsd.saveplot(filename+"\\WZSD.jpg");
       emit done();
       quit();
       wait();
   }
signals:
   void done();

};


class IThread : public QThread
{
   Q_OBJECT
public:
   IThread(QObject *parent = 0)
       : QThread(parent)
   {
       moveToThread(this);
   }

   QString filename;
   void getname(QString a)
   {
       filename = a;
   }
   WZSD showI;
protected:
   void run()
   {
       bool ok;
       long Ia,Ib;
       //WZSD showI;
       //WorkerThread *thread = new WorkerThread(this);
       showI.legendname(1);
       QFile Iain(filename+"\\Ia.txt");
       if(!Iain.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug()<<"Can't open the file!"<<endl;
       }

       QFile Ibin(filename+"\\Ib.txt");
       if(!Ibin.open(QIODevice::ReadOnly | QIODevice::Text)) {
           qDebug()<<"Can't open the file!"<<endl;
       }

       while(!Iain.atEnd()) {

           QByteArray line = Iain.readLine();
           QString str2(line);
           Ia = str2.toLong(&ok,10);

           line = Ibin.readLine();
           QString str3(line);
           Ib = str3.toLong(&ok,10);

           showI.wzsdshow(Ia,Ib);

       }

       //showI.show();
       showI.saveplot(filename+"\\IdIq.jpg");
       emit done();
       quit();
       wait();
   }
signals:
   void done();
};


#endif // THREAD_H
