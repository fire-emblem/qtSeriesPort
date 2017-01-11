#include "spcomm.h"


//构造函数，添加初始化函数
SPComm::SPComm(QObject *parent) : QObject(parent)
{
    m_serialPort = new QSerialPort();
    m_portName = "";
    m_baudRate = QSerialPort::Baud9600;
    m_databit = QSerialPort::Data8;
    m_veritybit = QSerialPort::NoParity;
    m_stopbit = QSerialPort::OneStop;
}
//析构函数，删除数据
SPComm::~SPComm()
{
    delete m_serialPort;
}

bool SPComm::isOpen() const
{
    return m_serialPort->isOpen();
}

//获得串口故障信息
QString SPComm::getError()
{
    QSerialPort::SerialPortError serialporterror;
    serialporterror = m_serialPort->error();

    if(serialporterror==QSerialPort::NoError)
    {
        return "NoError";
    }
    else if(serialporterror==QSerialPort::DeviceNotFoundError)
    {
        return "DeviceNotFoundError";
    }
    else if(serialporterror==QSerialPort::PermissionError)
    {
        return "PermissionError";
    }
    else if(serialporterror==QSerialPort::OpenError)
    {
        return "OpenError";
    }
    else if(serialporterror==QSerialPort::ParityError)
    {
        return "ParityError";
    }
    else if(serialporterror==QSerialPort::FramingError)
    {
        return "FramingError";
    }
    else if(serialporterror==QSerialPort::BreakConditionError)
    {
        return "BreakConditionError";
    }
    else if(serialporterror==QSerialPort::WriteError)
    {
        return "WriteError";
    }
    else if(serialporterror==QSerialPort::ReadError)
    {
        return "ReadError";
    }
    else if(serialporterror==QSerialPort::ResourceError)
    {
        return "ResourceError";
    }
    else if(serialporterror==QSerialPort::UnsupportedOperationError)
    {
        return "UnsupportedOperationError";
    }
    else if(serialporterror==QSerialPort::UnknownError)
    {
        return "UnknownError";
    }
    else if(serialporterror==QSerialPort::TimeoutError)
    {
        return "TimeoutError";
    }
    else if(serialporterror==QSerialPort::NotOpenError)
    {
        return "NotOpenError";
    }
}
//设置串口的名字
void SPComm::setPortName(const QString &name)
{
    m_portName = name;
}
//获取串口的名字
QString SPComm::portName() const
{
    return m_portName;
}

//设置串口的波特率
void SPComm::setBaudRate(int baudRate)
{
    m_baudRate = baudRate;
}
//设置数据位
void SPComm::setDatabit(int databit)
{
    m_databit = databit;
}

//设置校验位
void SPComm::setVeritybit(QString veritybit)
{
    m_veritybit = veritybit;
}

//设置停止位
void SPComm::setStopbit(int stopbit)
{
    m_stopbit = stopbit;
}
//获取串口波特率
//int SPComm::BaudRate() const
QSerialPort::BaudRate SPComm::getBaudRate(int baudRate)
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
QSerialPort::DataBits SPComm::getDatabit(int databit)
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
QSerialPort::Parity SPComm::getVeritybit(QString veritybit)
{
    if(veritybit=="None")
    {
        return QSerialPort::NoParity;
    }
    else if(veritybit=="Even")
    {
        return QSerialPort::EvenParity;
    }
    else if(veritybit=="Odd")
    {
        return QSerialPort::OddParity;
    }
    else if(veritybit=="Space")
    {
        return QSerialPort::SpaceParity;
    }
    else if(veritybit=="Mark")
    {
        return QSerialPort::MarkParity;
    }
    else
    {
        return QSerialPort::UnknownParity;
    }
}
//获取停止位
QSerialPort::StopBits SPComm::getStopbit(int stopbit)
{
    switch(stopbit)
    {
        case 1:         return QSerialPort::OneStop;
        case 2:         return QSerialPort::TwoStop;
        default:        return QSerialPort::UnknownStopBits;
    }
}
//设置setDataTerminalReady
void SPComm::setDataTerminalReady(bool val)
{
    m_serialPort->setDataTerminalReady(val);
}
//打开串口
bool SPComm::open()
{
    if(m_serialPort->isOpen())
    {
        return true;
    }
    m_serialPort->setPortName(m_portName);
    m_serialPort->setBaudRate(getBaudRate(m_baudRate));
    m_serialPort->setParity(getVeritybit(m_veritybit));
    m_serialPort->setDataBits(getDatabit(m_databit));
    m_serialPort->setStopBits(getStopbit(m_stopbit));
    m_serialPort->setFlowControl(QSerialPort::NoFlowControl);
    m_serialPort->setReadBufferSize(1024);
//m_serialPort->DataSetReadySignal
    //m_serialPort->setQueryMode(EventDriven);//设置事件驱动
//m_serialPort.setDataTerminalReady(true);


    return m_serialPort->open(QSerialPort::ReadWrite);
}

//关闭串口
void SPComm::close()
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->close();

    }
}

//重启串口，清除数据
bool SPComm::clear()
{
    if(m_serialPort->isOpen())
    {
        m_serialPort->clear();
        this->close();
        return this->open();
    }
    return false;
}

//获取电脑上的串口列表
QStringList SPComm::getSerialPortID()
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

//用来接收串口发来的数据
int SPComm::readData(char *buffer,int count,int timeout)
{
    int len = 0;
    forever
    {
        int n = m_serialPort->read(&buffer[len],count - len);
        if(n==-1)
        {
            return -1;
        }
        else if(n==0 && !m_serialPort->waitForReadyRead(timeout))
        {
            return -2;
        }
        else
        {
            len += n;
            if(count==len)
            {
                break;
            }
        }
    }
    return len;
}


//发送数据到串口
int SPComm::writeData(char *data,int size)
{
    int len = 0;
    forever
    {
        int n = m_serialPort->write(&data[len],size-len);
        if(n==-1)
        {
            return -1;
        }
        else
        {
            len += n;
            if(size==len) break;
        }
    }
    return len;
}
