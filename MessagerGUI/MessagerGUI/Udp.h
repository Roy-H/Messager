#pragma once
#include<memory>
#include<thread>
#include<HPSocket.h>
#include<HPTypeDef.h>
#include "Config.h"
#include "IMessageHub.h"
class UdpServerListener :public CUdpServerListener
{
	public:
		virtual EnHandleResult OnPrepareListen(IUdpServer* pSender, SOCKET soListen) override;
		virtual EnHandleResult OnAccept(IUdpServer* pSender, CONNID dwConnID, UINT_PTR pSockAddr) override;
		virtual EnHandleResult OnHandShake(IUdpServer* pSender, CONNID dwConnID) override;
		virtual EnHandleResult OnReceive(IUdpServer* pSender, CONNID dwConnID,const BYTE* pData, int iLength)override;
		virtual EnHandleResult OnSend(IUdpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength)override;
		virtual EnHandleResult OnShutdown(IUdpServer* pSender)override;
		virtual EnHandleResult OnClose(IUdpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode) override;

public:
	void SetMessageHub(IMessageHub* messageHub) { mMessageHub = messageHub; };
private:
	IMessageHub *mMessageHub = nullptr;
};


class UdpClientListener:public CUdpClientListener
{
	virtual EnHandleResult OnPrepareConnect(IUdpClient* pSender, CONNID dwConnID, SOCKET socket) override;
	virtual EnHandleResult OnConnect(IUdpClient* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnHandShake(IUdpClient* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnReceive(IUdpClient* pSender, CONNID dwConnID,const BYTE* pData, int iLength) override;
	virtual EnHandleResult OnSend(IUdpClient* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;
	virtual EnHandleResult OnClose(IUdpClient* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)override;
};

class Udp
{
public:
	void StartServer(IMessageHub* messageHun = nullptr);
	void StopServer();
	void StartClient();
	void StopClient();
	~Udp()
	{
		if(m_udpServerListener_ptr)
			delete m_udpServerListener_ptr;
		if (m_udpClientListener_ptr)
			delete m_udpClientListener_ptr;
		if (m_server_ptr)
			delete m_server_ptr;
		if (m_client_ptr)
			delete m_client_ptr;
	}
private:
	//std::shared_ptr<CUdpServerListener> m_udpServer_ptr;
	UdpServerListener *m_udpServerListener_ptr = nullptr;
	UdpClientListener *m_udpClientListener_ptr = nullptr;
	CUdpServerPtr *m_server_ptr;
	CUdpClientPtr *m_client_ptr;
};
