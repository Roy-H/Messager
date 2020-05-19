#include "Udp.h"
#include "BasicMessageHub.h"
#include <QMessageBox>
#include <thread>
#include "ThreadPool.h"
#include<iostream>
//server start
EnHandleResult UdpServerListener::OnPrepareListen(IUdpServer * pSender, SOCKET soListen)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnAccept(IUdpServer * pSender, CONNID dwConnID, UINT_PTR pSockAddr)
{
	//create helper by helper factory;
	//MessageHelper* helper = new MessageHelper(std::shared_ptr<BasicMessageHub>(mMessageHub));
	//mMessageHub->AddHelper(dwConnID, helper);
	//pSender->SetConnectionExtra(dwConnID, helper);
	return HR_OK;
}

EnHandleResult UdpServerListener::OnHandShake(IUdpServer * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult UdpServerListener::OnReceive(IUdpServer * pSender, CONNID dwConnID, const BYTE* pData, int iLength)
{
	//考虑到udp的特殊性不做特殊处理，直接将所有数据读出
	unsigned char *data = new unsigned char[iLength]();
	memcpy(data, pData, iLength);

	mPool_ptr->enqueue([] {
		//std::cout << "thread id:" << std::this_thread::get_id() << std::endl;
		auto id = std::this_thread::get_id();
		//int a = id._To_text();
		//std::cout << "thread id:" << std::this_thread::get_id();
		qDebug() << "sdasdasdsadasdasdsa";
	});
	//auto worker = std::thread(&IMessageHub::RecognizeMsgPackage, mMessageHub, dwConnID, data, iLength);
	//worker.detach();

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
	
	qDebug() << "错误码：" << iErrorCode;
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

void Udp::StartServer()
{
	if (m_udpServerListener_ptr == nullptr)
	{
		m_udpServerListener_ptr = new UdpServerListener();
		if (mMessageHub == nullptr)
		{
			mMessageHub = new BasicMessageHub();
		}
		m_udpServerListener_ptr->SetMessageHub(mMessageHub);

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


