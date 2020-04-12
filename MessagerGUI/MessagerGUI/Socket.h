#pragma once
#include<QTcpSocket>
#include<QUdpSocket>
#include <QHostAddress>
#include <QMessageBox>

class SocketBase
{

};

class TcpSocket:public SocketBase
{
public:

private:
	std::shared_ptr<QTcpSocket> m_tcpClient_ptr;
};

class UdpSocket:public SocketBase
{

};

