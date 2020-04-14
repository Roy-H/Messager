#include "Socket.h"

TcpSocket::TcpSocket()
{
	InitSocket();
}

void TcpSocket::Send(QString str)
{
	QByteArray bytes = str.toUtf8();
	//m_tcpsock.writeData(bytes, bytes.size());
}

void TcpSocket::Connect()
{
	m_tcpsock.connectToHost("127.0.0.1",7756);
	if (m_tcpsock.waitForConnected(1000))  // 连接成功则进入if{}
	{
		qDebug() << "connect ok";
	}
}

void TcpSocket::InitSocket()
{
	//m_tcpsock_ptr = std::make_shared<QTcpSocket>(this);
	m_tcpsock.bind(QHostAddress::LocalHost, 7755);

	connect(&m_tcpsock, &QTcpSocket::readyRead,
		this, &TcpSocket::readPendingDatagrams);
}

void TcpSocket::readPendingDatagrams()
{
	
	auto data = m_tcpsock.read(1500);
	QString str(data);
	qDebug() << str;
	//m_tcpsock
	//while (m_tcpsock.hasPendingDatagrams()) {
	//	QNetworkDatagram datagram = m_tcpsock.receiveDatagram();
	//	qDebug() << datagram.data();
	//	//processTheDatagram(datagram);
	//}
}

UdpSocket::UdpSocket()
{
	InitSocket();
}

void UdpSocket::InitSocket()
{
	//m_udpsock_ptr = std::make_shared<QUdpSocket>(this);
	m_udpsock.bind(QHostAddress::LocalHost, 7755);
	
	connect(&m_udpsock, &QUdpSocket::readyRead,
		this, &UdpSocket::readPendingDatagrams);
}

void UdpSocket::Send(QString str)
{
	QByteArray bytes = str.toUtf8();
	m_udpsock.writeDatagram(bytes, bytes.size(), QHostAddress::LocalHost, 7754);
}

void UdpSocket::readPendingDatagrams()
{
	while (m_udpsock.hasPendingDatagrams()) {
		QNetworkDatagram datagram = m_udpsock.receiveDatagram();
		qDebug() << datagram.data();
		//processTheDatagram(datagram);
	}
}
