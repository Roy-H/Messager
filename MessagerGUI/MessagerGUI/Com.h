#pragma once
#include<memory>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QObject>
#include<qDebug>
class Com:public QObject
{
	Q_OBJECT
public:
	Com(QSerialPortInfo info);
	
	typedef std::shared_ptr<Com> ptr;
	static QList<QSerialPortInfo> GetAllComPorts();
	static QSerialPortInfo Find(const QString serial_num);
	
	void Send(const QString& dat);
	void Recevied();
public slots:
	void ReadyReadSlot();
private:
	std::string m_name;
	std::string m_description;
	std::string m_manufacturer;
	std::string m_serial_number;
	std::string m_system_location;
	std::shared_ptr<QSerialPortInfo> m_QSerialPortInfo_ptr;
	QSerialPort m_reader;
	QSerialPort m_sender;

};