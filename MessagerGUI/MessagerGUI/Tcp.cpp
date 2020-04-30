#include "Tcp.h"
#include "BasicMessageHub.h"
#include <QMessageBox>
//server start
EnHandleResult TcpServerListener::OnPrepareListen(ITcpServer * pSender, SOCKET soListen)
{
	return HR_OK;
}

EnHandleResult TcpServerListener::OnAccept(ITcpServer * pSender, CONNID dwConnID, UINT_PTR pSockAddr)
{
	return HR_OK;
}

EnHandleResult TcpServerListener::OnHandShake(ITcpServer * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult TcpServerListener::OnReceive(ITcpServer * pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	if (mMessageHub)
	{
		mMessageHub->HandleData((char*)pData, iLength);
	}
	return HR_OK;
}

EnHandleResult TcpServerListener::OnReceive(ITcpServer * pSender, CONNID dwConnID, int iLength)
{
	/*if (mMessageHub)
	{
		mMessageHub->HandleData((char*)pData, iLength);
	}*/
	return HR_OK;
}

EnHandleResult TcpServerListener::OnSend(ITcpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpServerListener::OnShutdown(ITcpServer * pSender)
{
	return HR_OK;
}

EnHandleResult TcpServerListener::OnClose(ITcpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	qDebug << "错误码：" << iErrorCode;
	QMessageBox::about(NULL, "warn", QString::fromLocal8Bit("udp 服务端 连接关闭！"));
	return HR_OK;
}

//Server end

//Client start
EnHandleResult TcpClientListener::OnPrepareConnect(ITcpClient * pSender, CONNID dwConnID, SOCKET socket)
{
	return EnHandleResult();
}

EnHandleResult TcpClientListener::OnConnect(ITcpClient * pSender, CONNID dwConnID)
{
	return EnHandleResult();
}

EnHandleResult TcpClientListener::OnHandShake(ITcpClient * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnReceive(ITcpClient * pSender, CONNID dwConnID, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnSend(ITcpClient * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnClose(ITcpClient * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	QMessageBox::about(NULL, "warn", QString::fromLocal8Bit("udp 客户端 连接关闭！"));
	return HR_OK;
}
//client end

void Tcp::StartServer(IMessageHub* messageHub = nullptr)
{
	if (m_tcpServerListener_ptr == nullptr)
	{
		m_tcpServerListener_ptr = new TcpServerListener();
		if (messageHub == nullptr)
		{
			messageHub = new BasicMessageHub();
		}
		m_tcpServerListener_ptr->SetMessageHub(messageHub);

		m_server_ptr = new CTcpPullServerPtr(m_tcpServerListener_ptr);
	}

	(*m_server_ptr)->Start((LPCTSTR)Config::sServerIp, Config::sServerPort);

}

void Tcp::StopServer()
{
	(*m_server_ptr)->Stop();
}

void Tcp::StartClient()
{
	if (m_tcpClientListener_ptr == nullptr)
	{
		m_tcpClientListener_ptr = new TcpClientListener();
		m_client_ptr = new CTcpPullClientPtr(m_tcpClientListener_ptr);
	}

	(*m_client_ptr)->Start((LPCTSTR)Config::sClientIp, Config::sClientPort);
}

void Tcp::StopClient()
{
	(*m_client_ptr)->Stop();
}

EnHandleResult TcpClientListener::OnPrepareConnect(ITcpClient * pSender, CONNID dwConnID, SOCKET socket)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnConnect(ITcpClient * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnHandShake(ITcpClient * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnReceive(ITcpClient * pSender, CONNID dwConnID, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnSend(ITcpClient * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpClientListener::OnClose(ITcpClient * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	return HR_OK;
}
