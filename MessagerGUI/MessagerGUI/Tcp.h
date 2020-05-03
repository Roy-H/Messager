#pragma once

#include<memory>
#include<thread>
#include<HPSocket.h>
#include<HPTypeDef.h>
#include "Config.h"
#include "IMessageHub.h"
class TcpServerListener :public CTcpPullServerListener
{
public:
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen) override;
	virtual EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR pSockAddr) override;
	virtual EnHandleResult OnHandShake(ITcpServer* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)override;
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength)override;
	virtual EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)override;
	virtual EnHandleResult OnShutdown(ITcpServer* pSender)override;
	virtual EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode) override;

public:
	void SetMessageHub(IMessageHub* messageHub) { mMessageHub = messageHub; };
private:
	IMessageHub * mMessageHub = nullptr;
};

class TcpClientListener :public CTcpPullClientListener
{
	virtual EnHandleResult OnPrepareConnect(ITcpClient* pSender, CONNID dwConnID, SOCKET socket) override;
	virtual EnHandleResult OnConnect(ITcpClient* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnHandShake(ITcpClient* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnReceive(ITcpClient* pSender, CONNID dwConnID, int iLength)override;
	virtual EnHandleResult OnSend(ITcpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;
	virtual EnHandleResult OnClose(ITcpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)override;
};

class Tcp
{
public:
	void StartServer(IMessageHub* messageHun);
	void StopServer();
	void StartClient();
	void StopClient();
	~Tcp()
	{
		if (m_tcpServerListener_ptr)
			delete m_tcpServerListener_ptr;
		if (m_tcpClientListener_ptr)
			delete m_tcpClientListener_ptr;
		if (m_server_ptr)
			delete m_server_ptr;
		if (m_client_ptr)
			delete m_client_ptr;
	}
private:
	//std::shared_ptr<CUdpServerListener> m_udpServer_ptr;
	TcpServerListener * m_tcpServerListener_ptr = nullptr;
	TcpClientListener *m_tcpClientListener_ptr = nullptr;
	CTcpPullServerPtr *m_server_ptr;
	CTcpPullClientPtr *m_client_ptr;
};
