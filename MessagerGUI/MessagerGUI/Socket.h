#pragma once
#include<QTcpSocket>
#include<QUdpSocket>
#include <QHostAddress>
#include<QNetworkDatagram>
#include <QMessageBox>

class ISocketBase:public QObject
{
	Q_OBJECT
public:
	virtual void InitSocket() = 0;
};

class TcpSocket:public ISocketBase
{
	Q_OBJECT
public:
	typedef std::shared_ptr<TcpSocket> ptr;
	TcpSocket();
	virtual void Send(QString str);
	virtual void Connect();
	virtual void InitSocket() override;
public slots:
	void readPendingDatagrams();
private:
	//std::shared_ptr<QTcpSocket> m_tcpsock_ptr;
	QTcpSocket m_tcpsock;
};

class UdpSocket:public ISocketBase
{
	Q_OBJECT
public:
	typedef std::shared_ptr<UdpSocket> ptr;
	UdpSocket();
	
	virtual void InitSocket() override;
	virtual void Send(QString str);
public slots:
	void readPendingDatagrams();
private:
	//std::shared_ptr<QUdpSocket> m_udpsock_ptr;
	QUdpSocket m_udpsock;
};

