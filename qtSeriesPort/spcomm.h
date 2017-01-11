#ifndef SPCOMM_H
#define SPCOMM_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QComboBox>

class SPComm : public QObject
{
    Q_OBJECT
public:
    explicit SPComm(QObject *parent = 0);
    ~SPComm();

    bool isOpen() const;

    void setPortName(const QString &name);
    QString portName() const;

    void setBaudRate(int baudRate);
    int BaudRate() const;

    void setDatabit(int databit);
    int Databit() const;

    void setVeritybit(QString veritybit);
    int Veritybit() const;

    void setStopbit(int stopbit);
    int Stopbit() const;

    void setDataTerminalReady(bool val);

    virtual bool open();
    virtual void close();
    virtual bool clear();

    QString getError(void);

    int readData(char *buffer,int count,int timeout=1000);
    int writeData(char *data,int size);
    int write(char ch);

    QStringList getSerialPortID();

protected:
    QString m_portName;
    int m_baudRate;
    int m_databit;
    QString m_veritybit;
    int m_stopbit;

    QSerialPort *m_serialPort;

private:
    QSerialPort::BaudRate getBaudRate(int baudRate);
    QSerialPort::DataBits getDatabit(int databit);
    QSerialPort::Parity getVeritybit(QString veritybit);
    QSerialPort::StopBits getStopbit(int stopbit);

signals:

public slots:
};

#endif // SPCOMM_H
