#include "Com.h"
#include<QList>
#include<QString>
#include<QByteArray>
#include<QMessageBox>

Com::Com(QSerialPortInfo info)
{
	m_reader.setPort(info);
	if (m_reader.open(QIODevice::ReadWrite))
	{
		qDebug() << "m_reader.open(QIODevice::ReadWrite)";
		m_reader.setBaudRate(QSerialPort::Baud9600);
		m_reader.setParity(QSerialPort::NoParity);
		m_reader.setDataBits(QSerialPort::Data8);
		m_reader.setStopBits(QSerialPort::OneStop);
		m_reader.setFlowControl(QSerialPort::NoFlowControl);

		m_reader.clearError();
		m_reader.clear();		

		connect(&m_reader, SIGNAL(readyRead()), this, SLOT(ReadyReadSlot()));
		
	}
	/*if (m_sender.open(QIODevice::ReadWrite))
	{
		qDebug() << "m_reader.open(QIODevice::ReadWrite)";
		m_sender.setBaudRate(QSerialPort::Baud9600);
		m_sender.setParity(QSerialPort::NoParity);
		m_sender.setDataBits(QSerialPort::Data8);
		m_sender.setStopBits(QSerialPort::OneStop);
		m_sender.setFlowControl(QSerialPort::NoFlowControl);

		m_sender.clearError();
		m_sender.clear();
		
		connect(&m_sender, SIGNAL(readwrite()), this, SLOT(ReadyReadSlot()));

	}*/
	
}

QList<QSerialPortInfo> Com::GetAllComPorts()
{
	return QSerialPortInfo::availablePorts();
}

QSerialPortInfo Com::Find(const QString serial_num)
{
	auto list = QSerialPortInfo::availablePorts();
	if (list.length() <= 0)
	{
		QMessageBox::about(NULL, "错误", "没有可用的端口");
	}

	for (auto i = list.begin(); i != list.end(); i++)
	{
		qDebug() << i->portName() << "\n";
		if (i->portName().contains(serial_num))
		{
			return *i;
			
		}
	}
	return *list.begin();
	// TODO: insert return statement here
}


void Com::Send(const QString& dat )
{
	//char dat[] = { 0x55,0x01,0x05,0x00,0xAA };
	QByteArray bytes = dat.toUtf8();
	m_reader.write(bytes);
}

void Com::Recevied()
{
	//m_serialPort.
}

void Com::ReadyReadSlot()
{
	qDebug() << "x";
	QByteArray arr = m_reader.readAll();
	QString str(arr);
	QMessageBox::information(NULL, "Title", str,
		QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	
}



