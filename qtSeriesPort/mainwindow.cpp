#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QIODevice>
int zhuan = 0;

int P_SIZE = 8;
int V_SIZE = 8;
int A_SIZE = 8;
int B_SIZE = 8;
int C_SIZE = 4;

int CHANGDU = 38;

int ShowCount = 0;

int L1 = 2;     // AA
int L2 = 0;		//AABB
int L3 = 0;		//BBCC
int L4 = 0;		//CCDD



long dataWZH = 0;
long dataSDH = 0;
long dataIaH = 0;
long dataIbH = 0;
long dataIbL = 0;
long dataIaL = 0;
long dataWZL = 0;
long dataSDL = 0;
long dataWZ = 0;
long dataSD = 0;
long dataIa = 0;
long dataIb = 0;


QString strWZH,strWZL,strIaH,strIbH;
QString strSDH,strSDL,strIaL,strIbL;
QString fileadd;

bool ShowSwitch = 0;

void JS_P(QString &,long &,long &,long &,long &,long &);
template <typename T>
void JS_S(QString &s,int i,int j,T& a);

bool ShowEnable = 0;

QString  backt();
QString  Ttran(int );
QString  backtday();

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMaximumSize(962,529);
    this->setMinimumSize(962,529);
    ui->tabWidget->backgroundRole();
    m_spcomm = new QSerialPort();

    //设置窗体背景颜色
    QPalette palette,p;
    //palette.setColor(QPalette::All, QColor(176,196,222));
    palette.setColor(QPalette::Background, QColor(176,196,222));
    this->setPalette(palette);
    //ui->seWindowIcon(QIcon("19.ico"));
    //
   //ui->tabWidget->setStyleSheet("background-color:rgb(176,196,222)");
   // ui->tabWidget->setStyleSheet("background-color:rgb(128,128,128),color:rgb(176,196,222)");






    this->setWindowIcon(QIcon("19.ico"));

    qSerialPortStatus = false;
    qReceiveNum = 0;
    qSendNum = 0;
    qSendCycle = 1000;
    qSendHex = true;
    qAutoSend = false;

    //定义定时器
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate())); //定时器槽函数
    timer->start(qSendCycle);  //设置定时器定时间隔时间，并启动

    //设置串口接收定时器，主要用于检测串口什么时候发送完一帧数据
    timerCom = new QTimer();
    connect(timerCom,SIGNAL(timeout()),this,SLOT(timerComUpDate()));

    //设置edtSendCycle只能输入1~100000的整数
    ui->edtSendCycle->setValidator(new QIntValidator(1, 100000, ui->edtSendCycle));

    brushStatus();
    SerialPortStatusChange(qSerialPortStatus);

    ui->edtSendText->clear();

    ui->edtSendCycle->setText(QString::number(qSendCycle));


    ui->edtShowWZ->setReadOnly(true);                  //设置显示窗口只读
    ui->edtShowSD->setReadOnly(true);
    ui->edtShowId->setReadOnly(true);
    ui->edtShowIq->setReadOnly(true);
    ui->edtShowMove->setReadOnly(true);
    ui->edtShowcontrol->setReadOnly(true);
    ui->edtShowseri->setReadOnly(true);
    /*
    ui->edtShowPp->setReadOnly(true);
    ui->edtShowVp->setReadOnly(true);
    ui->edtShowVi->setReadOnly(true);
    ui->edtShowIp->setReadOnly(true);
    ui->edtShowIi->setReadOnly(true);
    */



    ui->chkAutoSend->setChecked(qAutoSend);
    ui->chkSendHex->setChecked(qSendHex);

    //获取电脑上的串口名称
    ui->cmbSerialPortName->addItems(getSerialPortID());


    ui->cmbBaudRate->addItem("1200");
    ui->cmbBaudRate->addItem("2400");
    ui->cmbBaudRate->addItem("4800");
    ui->cmbBaudRate->addItem("9600");
    ui->cmbBaudRate->addItem("19200");
    ui->cmbBaudRate->addItem("38400");
    ui->cmbBaudRate->addItem("57600");
    ui->cmbBaudRate->addItem("115200");
    ui->cmbBaudRate->setCurrentIndex(7);

    ui->cmbDatabit->addItem("5");
    ui->cmbDatabit->addItem("6");
    ui->cmbDatabit->addItem("7");
    ui->cmbDatabit->addItem("8");
    ui->cmbDatabit->setCurrentIndex(3);

    ui->cmbVeritybit->addItem("None");
    ui->cmbVeritybit->addItem("Odd");
    ui->cmbVeritybit->addItem("Even");
    ui->cmbVeritybit->addItem("Mark");
    ui->cmbVeritybit->addItem("Space");
    ui->cmbVeritybit->setCurrentIndex(0);

    ui->cmbStopbit->addItem("1");
    ui->cmbStopbit->addItem("2");
    ui->cmbStopbit->setCurrentIndex(0);

    ui->cmbCircle->addItem("P Circle");      //控制环下拉窗
    ui->cmbCircle->addItem("V Circle");
    ui->cmbCircle->addItem("I Circle");
    ui->cmbCircle->setCurrentIndex(0);

    ui->cmbPI->addItem("P");                 //比例积分下拉窗
    ui->cmbPI->addItem("I");
    ui->cmbPI->setCurrentIndex(0);

   /* QDoubleValidator *validator = new QDoubleValidator(0,9.999,3,this);

    validator->setNotation(QDoubleValidator::StandardNotation);
    ui->edtNum->setValidator(validator);*/




}

MainWindow::~MainWindow()
{
    delete m_spcomm;
    delete ui;
}

//定时器槽函数
void MainWindow::timerUpDate()
{
    if(qAutoSend)
    {
        my_senduart();
    }
}

void MainWindow::timerComUpDate()
{
    timerCom->stop();
}
//获取电脑上的串口列表
QStringList MainWindow::getSerialPortID()
{
    QSerialPortInfo* serialInfo;
    QList<QSerialPortInfo>serialList;
    QStringList serialPortAssitant;

    serialInfo = new QSerialPortInfo();
    serialList = serialInfo->availablePorts();
    int nSerialnum = serialList.length();

    for(int i=0;i<nSerialnum;i++)
    {
        QString serialName=serialList[i].portName();
        serialPortAssitant.insert(i,serialName);
    }
    return serialPortAssitant;
}

//获取串口波特率
QSerialPort::BaudRate MainWindow::getBaudRate(int baudRate)
{
    switch(baudRate)
    {
        case 1200:      return QSerialPort::Baud1200;
        case 2400:      return QSerialPort::Baud2400;
        case 4800:      return QSerialPort::Baud4800;
        case 9600:      return QSerialPort::Baud9600;
        case 19200:     return QSerialPort::Baud19200;
        case 38400:     return QSerialPort::Baud38400;
        case 57600:     return QSerialPort::Baud57600;
        case 115200:    return QSerialPort::Baud115200;
        default:        return QSerialPort::UnknownBaud;
    }
}

//获取数据位
QSerialPort::DataBits MainWindow::getDatabit(int databit)
{
    switch(databit)
    {
        case 5:         return QSerialPort::Data5;
        case 6:         return QSerialPort::Data6;
        case 7:         return QSerialPort::Data7;
        case 8:         return QSerialPort::Data8;
        default:        return QSerialPort::UnknownDataBits;
    }
}

//获取校验位
QSerialPort::Parity MainWindow::getParitybit(QString Paritybit)
{
    if(Paritybit=="None")
    {
        return QSerialPort::NoParity;
    }
    else if(Paritybit=="Even")
    {
        return QSerialPort::EvenParity;
    }
    else if(Paritybit=="Odd")
    {
        return QSerialPort::OddParity;
    }
    else if(Paritybit=="Space")
    {
        return QSerialPort::SpaceParity;
    }
    else if(Paritybit=="Mark")
    {
        return QSerialPort::MarkParity;
    }
    else
    {
        return QSerialPort::UnknownParity;
    }
}
//获取停止位
QSerialPort::StopBits MainWindow::getStopbit(int stopbit)
{
    switch(stopbit)
    {
        case 1:         return QSerialPort::OneStop;
        case 2:         return QSerialPort::TwoStop;
        default:        return QSerialPort::UnknownStopBits;
    }
}

int MainWindow::getCircle(QString Cir)     //获取环
{
    if(Cir == "P Circle")
        return 0;
    else if(Cir == "V Circle")
        return 1;
    else if(Cir == "I Circle")
        return 2;
    else return 3;


}

int MainWindow::getPI(QString PI)        //获取PI
{
    if(PI == "P")
        return 0;
    else if(PI == "I")
        return 1;
    else return 2;

}











//串口状态转换函数
void MainWindow::SerialPortStatusChange(bool SPStatus)
{
    if(SPStatus)
    {
        ui->lblSerialPortStatus->setText("打开");
        ui->butOpenSerialPort->setText("关闭串口");
        ui->chkAutoSend->setEnabled(true);
        ui->butSendData->setEnabled(true);

    }
    else
    {
        ui->lblSerialPortStatus->setText("关闭");
        ui->butOpenSerialPort->setText("打开串口");
        ui->chkAutoSend->setEnabled(false);
        ui->butSendData->setEnabled(false);
    }
}
//打开串口按钮单击事件
void MainWindow::on_butOpenSerialPort_clicked()
{
    if(!m_spcomm->isOpen())
    {

        m_spcomm->setPortName(ui->cmbSerialPortName->itemText(ui->cmbSerialPortName->currentIndex()));
        if(m_spcomm->open(QSerialPort::ReadWrite))
        {
            m_spcomm->setPortName(ui->cmbSerialPortName->itemText(ui->cmbSerialPortName->currentIndex()));
            m_spcomm->setBaudRate(getBaudRate(ui->cmbBaudRate->itemText(ui->cmbBaudRate->currentIndex()).toInt()));
            m_spcomm->setParity(getParitybit(ui->cmbVeritybit->itemText(ui->cmbVeritybit->currentIndex())));
            m_spcomm->setDataBits(getDatabit(ui->cmbDatabit->itemText(ui->cmbDatabit->currentIndex()).toInt()));
            m_spcomm->setStopBits(getStopbit(ui->cmbStopbit->itemText(ui->cmbStopbit->currentIndex()).toInt()));
            m_spcomm->setFlowControl(QSerialPort::NoFlowControl);
            m_spcomm->setReadBufferSize(2048000); //设置读缓冲区大小    修改接收缓存！！！

            qSerialPortStatus = true;
            SerialPortStatusChange(qSerialPortStatus); //更新串口状态

            connect(m_spcomm,SIGNAL(readyRead()),this,SLOT(my_readuart()));
        }
        else //未打开
        {
            QMessageBox::information(NULL,"Error",m_spcomm->errorString(),QMessageBox::Ok ,QMessageBox::Ok);
        }
    }
    else
    {
        m_spcomm->close();
        qSerialPortStatus = false;
        SerialPortStatusChange(qSerialPortStatus);
    }
}
//刷新接收、发送字节数显示
void MainWindow::brushStatus()
{
    ui->lblSendNum->setText(QString::number(qSendNum,10));
    ui->lblReceiveNum->setText(QString::number(qReceiveNum,10));
}
//刷新自动发送
void MainWindow::brushAutoSend()
{
    if(qAutoSend)
    {
        ui->edtSendCycle->setEnabled(false);
    }
    else
    {
        ui->edtSendCycle->setEnabled(true);
    }
}

//清空发送区显示按钮单击事件
void MainWindow::on_butClearSendText_clicked()
{
    ui->edtSendText->clear();
}
//清空接收区显示按钮单击事件
/*void MainWindow::on_butClearReceiveText_clicked()
{
    ui->edtReceiveText->clear();
}*/
//清除计数按钮单击事件
void MainWindow::on_butClearNum_clicked()
{
    qReceiveNum = 0;
    qSendNum = 0;
    brushStatus();
    QFile file("D:\\my project\\串口数据\\data1.txt");                               //清空data文件
    if(!file.open(QFile::WriteOnly))
    {
        QMessageBox::warning(this, tr("data"), tr("open filure"), QMessageBox::Ok);
        return ;
    }
    QTextStream out(&file);
    out<<" ";
    file.close();

}
//退出按钮单击事件
void MainWindow::on_butExit_clicked()
{
    close();
}
//自动发送复选框状态变化事件
void MainWindow::on_chkAutoSend_clicked()
{
    qAutoSend = !qAutoSend;
    brushAutoSend();
}
//发送十六进制复选框状态变化事件
void MainWindow::on_chkSendHex_clicked()
{
    qSendHex = !qSendHex;
}

//将一个字符串转换成十六进制
QByteArray MainWindow::String2Hex(QString str)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();  //获取字符串总长度
    QByteArray senddata;

    senddata.resize(len/2);  //为senddata数组开辟空间

    char lstr,hstr;
    for(int i=0; i<len;)
    {
        hstr = str[i].toLatin1(); //获得高位字符

        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1(); //获得低位字符
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata; //将高低位字符组合成十六进制
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
    return senddata;
}

//将一个字符转换成十六进制
char MainWindow::ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return (-1);
}

QByteArray MainWindow::String2Ascii(QString str)
{
    int len = str.length();     //获取字符串总长度
    QByteArray senddata;
    senddata.resize(len);       //为senddata数组开辟空间

    for(int i=0;i<len;i++)
    {
        senddata[i] = str[i].toLatin1();
    }
    return senddata;
}

//发送数据
void MainWindow::my_senduart()
{
    QByteArray SendData;

    if(qSendHex)
    {   //以十六进制发送
        SendData = String2Hex(ui->edtSendText->toPlainText());
    }
    else
    {   //以Ascii方式发送
        SendData = String2Ascii(ui->edtSendText->toPlainText());
    }

    m_spcomm->write(SendData);
    qSendNum = qSendNum + SendData.size(); //记录发送字节数
    brushStatus();  //刷新接收发送状态信息
}

//接收数据
void MainWindow::my_readuart()
{
    QByteArray byte;
    int nlong;
    QString nStr;
    //如果自动换行
    byte = m_spcomm->readAll();
    //byte = m_spcomm->read(1);
    nlong = sizeof(byte);
    if(nlong != 0)
    {
        QString buf;
        QString needdata;
        bool ok;
        nStr = byte.toHex();
        nStr = nStr.toUpper();
        nlong = nStr.size();
        nlong = nlong/2;
        qReceiveNum += nlong;
        //qDebug()<<nStr<<"\n";
        QString needfind = "DDED";
        QString gate ="AA";
        QString head ;
        int n = 0;
        int num = 0;
        while( nStr.indexOf(needfind,n) != -1)
        {
            num = nStr.indexOf(needfind,n);
            nStr = nStr.insert(num+4,"\r\n");

            head = nStr.mid(num - 34,2);
            if(head != gate)
            {
               // nStr = nStr.remove(lastnum+4,num+4);
                n=num+5;
                continue;

            }

                needdata = nStr.mid(num - 32,32);
               //needdata = needdata.toUpper();

                strWZH = needdata.left(4);
                strWZL = needdata.mid(4,4);

                strSDH = needdata.mid(8,4);
                strSDL = needdata.mid(12,4);

                strIaH = needdata.mid(16,4);
                strIaL = needdata.mid(20,4);

                strIbH = needdata.mid(24,4);
                strIbL = needdata.right(4);

                dataWZH = strWZH.toLong(&ok,16);
                dataWZL = strWZL.toLong(&ok,16);
                dataSDH = strSDH.toLong(&ok,16);
                dataSDL = strSDL.toLong(&ok,16);
                dataIaH = strIaH.toLong(&ok,16);
                dataIaL = strIaL.toLong(&ok,16);
                dataIbH = strIbH.toLong(&ok,16);
                dataIbL = strIbL.toLong(&ok,16);


                if(dataWZH >= 32768 )
                {
                    dataWZH = 65535 - dataWZH ;
                    dataWZL = 65535 - dataWZL +1;
                    dataWZ = -(65536*dataWZH +dataWZL);
                }
                else dataWZ = 65536*dataWZH +dataWZL;

                if(dataSDH >= 32768 )
                {
                    dataSDH = 65535 - dataSDH ;
                    dataSDL = 65535 - dataSDL +1;
                    dataSD = -(65536*dataSDH +dataSDL);
                }
                else dataSD = 65536*dataSDH +dataSDL;

                if(dataIaH >= 32768 )
                {
                    dataIaH = 65535 - dataIaH ;
                    dataIaL = 65535 - dataIaL +1;
                    dataIa = -(65536*dataIaH +dataIaL);
                }
                else dataIa = 65536*dataIaH +dataIaL;

                if(dataIbH >= 32768 )
                {
                    dataIbH = 65535 - dataIbH ;
                    dataIbL = 65535 - dataIbL +1;
                    dataIb = -(65536*dataIbH +dataIbL);
                }
                else dataIb = 65536*dataIbH +dataIbL;

                if(ShowCount++ > 20)
                {
                    ui->edtShowWZ->setText(QString::number((double)dataWZ/100));
                    ui->edtShowSD->setText(QString::number((double)dataSD/100));
                    ui->edtShowId->setText(QString::number((double)dataIa/100000));
                    ui->edtShowIq->setText(QString::number((double)dataIb/100000));
                    ShowCount = 0;
                }



            n = num +5;
        }
        QFile file("D:\\my project\\串口数据\\data1.txt");
        if(!file.open(QFile::WriteOnly | QIODevice::Append)){
            QMessageBox::warning(this, tr("write"), tr("open filure"), QMessageBox::Ok);
            return ;
        }
        QTextStream out(&file);
        out<<nStr;
        file.close();
        //更新接收数据个数
        brushStatus();
    }
}

//手动发送数据槽函数
void MainWindow::on_butSendData_clicked()
{
    my_senduart();
}

//设置定时发送的时间间隔
void MainWindow::on_edtSendCycle_textChanged(const QString &arg1)
{
    timer->stop();
    timer->start(arg1.toInt());
}
//保存按钮槽函数
/*void MainWindow::on_butSaveData_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,"保存文本",QDir::currentPath(),tr("txt(*.txt)"));
    if(fileName.isEmpty())
    {
        QMessageBox::information(this,"Error Message","Plesase Select a Text File");
        return;
    }
    QFile *file=new QFile;
    file->setFileName(fileName);
    bool ok=file->open(QIODevice::WriteOnly);
    if(ok)
    {
        QTextStream out(file);
        out<<ui->edtReceiveText->toPlainText()<<"\r\n";
        file->close();
        delete file;
    }
    else
    {
        QMessageBox::information(this,"Error Messaage","File Save Error"+file->errorString());
        return;
    }
}*/
//关于按钮单击槽函数
void MainWindow::on_butAbout_clicked()
{
    aboutFrom.exec();
}

void MainWindow::on_butControl_clicked()            //生成控制字
{
    const double PE = 0.0001526;
    const double IE = 0.00001526;

    int circle = getCircle(ui->cmbCircle->itemText(ui->cmbCircle->currentIndex()));
    int PI = getPI(ui->cmbPI->itemText(ui->cmbPI->currentIndex()));
    QString num = ui->edtNum->text();
    double BS = num.toDouble();
    long a =0;
    if(PI == 0)
    {
        a = BS/PE;
    }
    else if( PI == 1)
    {
        a = BS/IE;
    }
    QString cont = showout(a);

    if(circle == 0 && PI == 0)      //位置环P调节
    {
        ui->edtSendText->setText("FE0E"+cont+"0EEF");
        ui->edtShowPp->setText(num);
    }

    if(circle == 1 && PI == 0)      //速度环P调节
    {
        ui->edtSendText->setText("FE0C"+cont+"0CEF");
        ui->edtShowVp->setText(num);
    }

    if(circle == 1 && PI == 1)      //速度环I调节
    {
        ui->edtSendText->setText("FE0D"+cont+"0DEF");
        ui->edtShowVi->setText(num);
    }

    if(circle == 2 && PI == 0)      //电流环P调节
    {
        ui->edtSendText->setText("FE0A"+cont+"0AEF");
        ui->edtShowIp->setText(num);
    }
    if(circle == 2 && PI == 1)      //电流环I调节
    {
        ui->edtSendText->setText("FE0B"+cont+"0BEF");
        ui->edtShowIi->setText(num);
    }
    if(circle == 0 && PI ==1)      //位置环没有I调节
    {
        ui->edtSendText->clear();
    }
}



QString MainWindow::showout(long a)
{
    QString out;
    QChar c;
    int b;
    while(a>0)
    {
        b = a % 16;
        switch(b)
        {
            case 0: out += "0";break;
            case 1: out += "1";break;
            case 2: out += "2";break;
            case 3: out += "3";break;
            case 4: out += "4";break;
            case 5: out += "5";break;
            case 6: out += "6";break;
            case 7: out += "7";break;
            case 8: out += "8";break;
            case 9: out += "9";break;
            case 10: out += "A";break;
            case 11: out += "B";break;
            case 12: out += "C";break;
            case 13: out += "D";break;
            case 14: out += "E";break;
            case 15: out += "F";break;

        }
        a= a / 16;
    }
    int leng = out.length();
    if(leng <4)
    {
        int i = 4 - leng;
        while( i != 0)
        {
            out += "0";
            i--;
        }
     }
    c = out[0];
    out[0] = out[3];
    out[3] = c;

    c = out[1];
    out[1] = out[2];
    out[2] = c;

    return out;
}




/*void MainWindow::on_butClosecom_clicked()     //关闭串口发送
{
    QByteArray SendData;
    SendData = String2Hex("FE 04 00 00 04 EF");
    m_spcomm->write(SendData);

}*/

/*void MainWindow::on_butOpencom_clicked()
{
    QByteArray SendData;
    SendData = String2Hex("FE 04 01 02 04 EF");
    m_spcomm->write(SendData);

}*/


void MainWindow::on_cmbPI_currentIndexChanged()
{
    int PI = getPI(ui->cmbPI->itemText(ui->cmbPI->currentIndex()));
    if(PI)
    {
        QRegExp rx("^\\b(0(\\.\\d{1,3})?)|1\\b ");
        QRegExpValidator *pReg = new QRegExpValidator(rx, this);
        ui->edtNum->setValidator(pReg);
    }
    else
    {
        QRegExp rx("^(\\d(\\.\\d{1,3})?|10)$");
        QRegExpValidator *pReg = new QRegExpValidator(rx, this);         //设置P的上限为10
        ui->edtNum->setValidator(pReg);
    }
}

void MainWindow::on_butDataresolve_clicked()                            //数据的处理和保存
{
    ui->butDataresolve->setEnabled(false);
    QString time = backt();
    QString day = backtday();

    QString docu = "D:\\实验数据\\"+day;
    QString shuju = "D:\\实验数据\\"+day+"\\"+time;

    fileadd = shuju;
    //qDebug()<<shuju;
    QDir *temp = new QDir;
    bool docuok = temp->exists(docu);
    if(docuok)
    {
        bool ok = temp->mkdir(shuju);

    }
    else
    {
        temp->mkdir(docu);
        temp->mkdir(shuju);

    }


    QFile file("D:\\my project\\串口数据\\data1.txt");               //待处理数据输入
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QFile dizhi("D:\\实验数据\\dizhi.txt");               //待处理数据输入
    if(!dizhi.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug()<<"Can't open the file!"<<endl;
    }
    QTextStream outdizhi(&dizhi);

    QFile WZD(shuju+"\\WZ.txt");                                   //WZ输出流
    if (!WZD.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outwz(&WZD);

    QFile SDD(shuju+"\\SD.txt");                                   //SD输出流
    if (!SDD.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outsd(&SDD);

    QFile IaD(shuju+"\\Ia.txt");                                   //Ia输出流
    if (!IaD.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outIa(&IaD);

    QFile IbD(shuju+"\\Ib.txt");                                    //Ib输出流
    if (!IbD.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outIb(&IbD);

    QFile IcD(shuju+"\\Ic.txt");                                    //Ic输出流
    if (!IcD.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outIc(&IcD);

    QFile PID(shuju+"\\PI.txt");                                   //控制器参数保留
    if (!PID.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream outPi(&PID);


    while(!file.atEnd())
    {
        long WZ=0;
        long SD=0;
        long Ia=0;
        long Ib=0;
        long Ic=0;
        QByteArray line = file.readLine();
        QString str(line);
        int leng = str.length();
        str = str.left(leng - 1);
        leng = str.length();
        if(str[leng-2] == 'E' && str[leng-1] == 'D' && str[0] == 'A' && leng == CHANGDU)
        {
            JS_P(str,WZ,SD,Ia,Ib,Ic);
            //showwzsd.wzsdshow(WZ,SD);

            outwz<<WZ<<"\r\n";
            outsd<<SD<<"\r\n";
            outIa<<Ia<<"\r\n";
            outIb<<Ib<<"\r\n";
            outIc<<Ic<<"\r\n";



        }
    }
    //showwzsd.saveplot(shuju+"\\WZSD.jpg");
    outPi<<"Position loop: P="+ui->edtShowPp->text()+"\r\n";
    outPi<<"Speed loop: P="+ui->edtShowVp->text()+"  I="+ui->edtShowVi->text()+"\r\n";
    outPi<<"Current loop: P="+ui->edtShowIp->text()+"  I="+ui->edtShowIi->text()+"\r\n";



    outdizhi<<shuju+"\\";
    dizhi.close();
    file.close();
    WZD.close();
    SDD.close();
    IaD.close();
    IbD.close();
    IcD.close();



    QMessageBox::about(this,"Congratulation","Data processing is complete!");
    ui->butDataresolve->setEnabled(true);





}

QString  backt()
{
    time_t t = time(0);
    tm *st = localtime(&t);
    QString ti;
    ti= Ttran(st->tm_hour)+"."+Ttran(st->tm_min)+"."+Ttran(st->tm_sec);
    return ti;

}

QString  backtday()
{
    time_t t = time(0);
    tm *st = localtime(&t);

    QString ti;
    ti= Ttran(st->tm_mon+1)+"."+Ttran(st->tm_mday);

    return ti;

}

QString  Ttran(int a)
{
    QString t;
    QChar i;
    int b;
    if(a == 0 )
    return "00";

    else{
            b = a%10;
            t = (char)( b + 48 );
            a = a/10;
            t += (char)( a + 48 );

            i = t[0];
            t[0] = t[1];
            t[1] = i;
            return t;
        }
}

void JS_P(QString &s,long &WZ,long &SD,long &Ia,long &Ib,long &Ic)
{

    QString a;

    JS_S(s,L1,L1+P_SIZE-1,WZ);
    JS_S(s,L1+L2+P_SIZE,L1+L2+P_SIZE+V_SIZE-1,SD);
    JS_S(s,L1+L2+L3+P_SIZE+V_SIZE,L1+L2+L3+P_SIZE+V_SIZE+A_SIZE-1,Ia);
    JS_S(s,L1+L2+L3+L4+P_SIZE+V_SIZE+A_SIZE,L1+L2+L3+L4+P_SIZE+V_SIZE+A_SIZE+B_SIZE-1,Ib);
    Ic = 0-Ia-Ib;

}

template <typename T>
void JS_S(QString &str,int i,int j,T& a)
    {
        int n=0;
        int count = 0;

        std::string s = str.toStdString();

        if(s[i] - 55 <= 0)
        for(n=j;n>=i;n--)
        {
            if(s[n] > 57 )
            {
                a += (  s[n] - 65   +10)*pow(16,count);
            }
            else a += (s[n] - 48)*pow(16,count);

            count++;
        }

        else
        {

            for(n=j;n>=i;n--)
            {
                switch(s[n])
                {
                    case 'F': a += 0*pow(16,count); break;
                    case 'E': a += 1*pow(16,count); break;
                    case 'D': a += 2*pow(16,count); break;
                    case 'C': a += 3*pow(16,count); break;
                    case 'B': a += 4*pow(16,count); break;
                    case 'A': a += 5*pow(16,count); break;
                    case '9': a += 6*pow(16,count); break;
                    case '8': a += 7*pow(16,count); break;
                    case '7': a += 8*pow(16,count); break;
                    case '6': a += 9*pow(16,count); break;
                    case '5': a += 10*pow(16,count); break;
                    case '4': a += 11*pow(16,count); break;
                    case '3': a += 12*pow(16,count); break;
                    case '2': a += 13*pow(16,count); break;
                    case '1': a += 14*pow(16,count); break;
                    case '0': a += 15*pow(16,count); break;
                    default : break;
                }
                count++;

            }
            a= a+1;
            a= -a;
        }

    }




void MainWindow::on_butDatashow_clicked()
{
/*
    bool ok;
    long Ia,Ib,WZ,SD;
    //WorkerThread *thread = new WorkerThread(this);
    showwzsd.legendname(0);
    showI.legendname(1);
    QFile Iain(fileadd+"\\Ia.txt");
    if(!Iain.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QFile Ibin(fileadd+"\\Ib.txt");
    if(!Ibin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QFile WZin(fileadd+"\\WZ.txt");
    if(!WZin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }

    QFile SDin(fileadd+"\\SD.txt");
    if(!SDin.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug()<<"Can't open the file!"<<endl;
    }
    while(!Iain.atEnd()) {

        QByteArray line = WZin.readLine();
        QString str(line);
        WZ = str.toLong(&ok,10);

        line = SDin.readLine();
        QString str1(line);
        SD = str1.toLong(&ok,10);

        line = Iain.readLine();
        QString str2(line);
        Ia = str2.toLong(&ok,10);

        line = Ibin.readLine();
        QString str3(line);
        Ib = str3.toLong(&ok,10);

        showwzsd.wzsdshow(WZ,SD);
        showI.wzsdshow(Ia,Ib);

    }
    showwzsd.show();
    showI.show();

    showwzsd.saveplot(fileadd+"\\WZSD.jpg");
    showI.saveplot(fileadd+"\\IdIq.jpg");*/
    //QObject::connect(threadA,SIGNAL(done()),this,SLOT(showpic()));
    threadA.getname(fileadd);
    threadB.getname(fileadd);


    threadA.start();
    threadB.start();



}


void MainWindow::on_butADRCcontrol_clicked()
{
    ADRCser(ui->edtR->text(),0);
    ADRCser(ui->edtT->text(),1);
    ADRCser(ui->edtH->text(),2);
    ADRCser(ui->edtD->text(),3);
    ADRCser(ui->edtB->text(),4);
    ADRCser(ui->edtEsoalf1->text(),5);
    ADRCser(ui->edtEsoalf2->text(),6);
    ADRCser(ui->edtEsoalf3->text(),7);
    ADRCser(ui->edtEsobeta1->text(),8);
    ADRCser(ui->edtEsobeta2->text(),9);
    ADRCser(ui->edtEsobeta3->text(),10);
    ADRCser(ui->edtNLSEF_alfa1->text(),11);
    ADRCser(ui->edtNLSEF_alfa2->text(),12);
    ADRCser(ui->edtNLSEF_beta1->text(),13);
    ADRCser(ui->edtNLSEF_beta2->text(),14);





}

void MainWindow::ADRCser( QString num,int i)
{
    const double JD = 0.001;
    double BS = num.toDouble();
    long a =0;
    a=BS/JD;
    QString cont = showout(a);
    switch(i)
    {
        case 0: ui->edtSendText->setText("FE10"+cont+"10EF");qDebug()<<cont; break;
        case 1: ui->edtSendText->setText("FE11"+cont+"11EF"); break;
        case 2: ui->edtSendText->setText("FE12"+cont+"12EF"); break;
        case 3: ui->edtSendText->setText("FE13"+cont+"13EF"); break;
        case 4: ui->edtSendText->setText("FE14"+cont+"14EF"); break;
        case 5: ui->edtSendText->setText("FE15"+cont+"15EF"); break;
        case 6: ui->edtSendText->setText("FE16"+cont+"16EF"); break;
        case 7: ui->edtSendText->setText("FE17"+cont+"17EF"); break;
        case 8: ui->edtSendText->setText("FE18"+cont+"18EF"); break;
        case 9: ui->edtSendText->setText("FE19"+cont+"19EF"); break;
        case 10: ui->edtSendText->setText("FE1A"+cont+"1AEF"); break;
        case 11: ui->edtSendText->setText("FE1B"+cont+"1BEF"); break;
        case 12: ui->edtSendText->setText("FE1C"+cont+"1CEF"); break;
        case 13: ui->edtSendText->setText("FE1D"+cont+"1DEF"); break;
        case 14: ui->edtSendText->setText("FE1E"+cont+"1EEF"); break;
        default : break;
    }
    on_butSendData_clicked();


}


void MainWindow::on_butMoveOn_clicked()
{
    ui->edtSendText->setText("FE 04 00 02 04 EF");         //打开电机
    on_butSendData_clicked();
    ui->edtShowMove->setText("电机打开");
}

void MainWindow::on_butMoveClose_clicked()
{
     ui->edtSendText->setText("FE 04 00 01 04 EF");         //关闭电机
     on_butSendData_clicked();
     ui->edtShowMove->setText("电机关闭");
}

void MainWindow::on_butPID_clicked()
{
    ui->edtSendText->setText("FE 05 01 00 05 EF");         //调整为PI控制器
    on_butSendData_clicked();
    ui->edtShowcontrol->setText("PI");
}


void MainWindow::on_butADRC_clicked()
{
    ui->edtSendText->setText("FE 05 02 00 05 EF");         //调整为ADRC控制器
    on_butSendData_clicked();
    ui->edtShowcontrol->setText("ADRC");
}

void MainWindow::on_butSeriOn_clicked()
{
    ui->edtSendText->setText("FE 04 02 00 04 EF");         //打开串口
    on_butSendData_clicked();
    ui->edtShowseri->setText("串口打开");
}

void MainWindow::on_butSeriClose_clicked()
{
    ui->edtSendText->setText("FE 04 01 00 04 EF");         //关闭串口
    on_butSendData_clicked();
    ui->edtShowseri->setText("串口关闭");
}
