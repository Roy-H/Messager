#include "Udp.h"
#include "BasicMessageHub.h"
#include <QMessageBox>
//server start
EnHandleResult UdpServerListener::OnPrepareListen(IUdpServer * pSender, SOCKET soListen)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnAccept(IUdpServer * pSender, CONNID dwConnID, UINT_PTR pSockAddr)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnHandShake(IUdpServer * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnReceive(IUdpServer * pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	if (mMessageHub)
	{
		mMessageHub->HandleData((char*)pData, iLength);
	}
	return HR_OK;
}

EnHandleResult UdpServerListener::OnSend(IUdpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnShutdown(IUdpServer * pSender)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnClose(IUdpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	qDebug << "错误码：" << iErrorCode;
	QMessageBox::about(NULL, "warn", QString::fromLocal8Bit("udp 服务端 连接关闭！"));
	return HR_OK;
}

//Server end

//Client start
EnHandleResult UdpClientListener::OnPrepareConnect(IUdpClient * pSender, CONNID dwConnID, SOCKET socket)
{
	return EnHandleResult();
}

EnHandleResult UdpClientListener::OnConnect(IUdpClient * pSender, CONNID dwConnID)
{
	return EnHandleResult();
}

EnHandleResult UdpClientListener::OnHandShake(IUdpClient * pSender, CONNID dwConnID)
{
	return EnHandleResult();
}

EnHandleResult UdpClientListener::OnReceive(IUdpClient * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return EnHandleResult();
}

EnHandleResult UdpClientListener::OnSend(IUdpClient * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return EnHandleResult();
}

EnHandleResult UdpClientListener::OnClose(IUdpClient * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	QMessageBox::about(NULL, "warn", QString::fromLocal8Bit("udp 客户端 连接关闭！"));
	return EnHandleResult();
}
//client end

void Udp::StartServer(IMessageHub* messageHub = nullptr)
{
	if (m_udpServerListener_ptr == nullptr)
	{
		m_udpServerListener_ptr = new UdpServerListener();
		if (messageHub == nullptr)
		{
			messageHub = new BasicMessageHub();
		}
		m_udpServerListener_ptr->SetMessageHub(messageHub);

		m_server_ptr = new CUdpServerPtr(m_udpServerListener_ptr);		
	}
	
	(*m_server_ptr)->Start((LPCTSTR)Config::sServerIp, Config::sServerPort);
	
}

void Udp::StopServer()
{
	(*m_server_ptr)->Stop();
}

void Udp::StartClient()
{
	if (m_udpClientListener_ptr == nullptr)
	{
		m_udpClientListener_ptr = new UdpClientListener();
		m_client_ptr = new CUdpClientPtr(m_udpClientListener_ptr);
	}

	(*m_client_ptr)->Start((LPCTSTR)Config::sClientIp, Config::sClientPort);
}

void Udp::StopClient()
{
	(*m_client_ptr)->Stop();
}


