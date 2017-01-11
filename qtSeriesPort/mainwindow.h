#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QObject>
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QTimer>
#include <QFileDialog>
#include <QTextStream>
#include "qabout.h"
#include "mtdlg.h"
#include "wzsd.h"
#include "qcustomplot.h"
#include <QDebug>
#include <time.h>
#include "thread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_butOpenSerialPort_clicked();

    void on_butClearSendText_clicked();

   // void on_butClearReceiveText_clicked();

    void on_butClearNum_clicked();

    void on_butExit_clicked();

    void on_chkAutoSend_clicked();

    void on_chkSendHex_clicked();

    void my_readuart();

    void on_butSendData_clicked();

    void timerUpDate();

    void on_edtSendCycle_textChanged(const QString &arg1);

    //void on_butSaveData_clicked();

    void on_butAbout_clicked();

    void timerComUpDate();

    void on_butControl_clicked();

    //void on_butClosecom_clicked();

    //void on_butOpencom_clicked();

    //void on_cmbPI_activated(const QString &arg1);

    void on_cmbPI_currentIndexChanged();

    void on_butDataresolve_clicked();

    void on_butDatashow_clicked();

    void on_butADRCcontrol_clicked();

    void on_butMoveOn_clicked();

    void on_butMoveClose_clicked();

    void on_butPID_clicked();

    void on_butADRC_clicked();

    void on_butSeriOn_clicked();

    void on_butSeriClose_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *m_spcomm;
    QTimer *timer;
    QTimer *timerCom;
    qAbout aboutFrom;
    mtDlg showdata;
    WZSDThread threadA;
    IThread threadB;
    WZSD yu;








    //记录串口状态
    bool qSerialPortStatus;
    //记录接收到的字节数量
    int qReceiveNum;
    //记录发送的字节数量
    int qSendNum;
    //发送周期（毫秒）
    int qSendCycle;
    //十六进制发送
    bool qSendHex;
    //十六进制接收
    bool qReceiveHex;
    //自动发送
    bool qAutoSend;
    //自动分行
    bool qAutoNewline;

    //串口状态转换函数
    void SerialPortStatusChange(bool SPStatus);
    //刷新接收、发送字节数显示
    void brushStatus();
    void brushAutoSend();
    void brushSendHex();
    void brushReceiveHex();
    void brushAutoNewline();

    int getCircle(QString );    //获取环函数
    int getPI(QString);         //获取PI的函数
    QString showout(long);      //long转string
    void ADRCser( QString num,int i);



    QStringList getSerialPortID();
    QSerialPort::BaudRate getBaudRate(int baudRate);
    QSerialPort::DataBits getDatabit(int databit);
    QSerialPort::Parity   getParitybit(QString Paritybit);
    QSerialPort::StopBits getStopbit(int stopbit);

    void my_senduart();
    char ConvertHexChar(char ch);
    QByteArray String2Hex(QString str);
    QByteArray String2Ascii(QString str);
};

#endif // MAINWINDOW_H
