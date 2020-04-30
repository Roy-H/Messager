#pragma once
#include"HPSocket.h"
#include"SocketInterface.h"
//#include"HPTypeDef.h

class TcpServer:public CTcpPullServerListener
{
	virtual EnHandleResult OnPrepareListen(ITcpServer* pSender, SOCKET soListen) override;
	virtual EnHandleResult OnAccept(ITcpServer* pSender, CONNID dwConnID, UINT_PTR soClient) override;
	virtual EnHandleResult OnHandShake(ITcpServer* pSender, CONNID dwConnID) override;
	virtual EnHandleResult OnReceive(ITcpServer* pSender, CONNID dwConnID, int iLength) override;
	virtual EnHandleResult OnSend(ITcpServer* pSender, CONNID dwConnID, const BYTE* pData, int iLength) override;
	virtual EnHandleResult OnShutdown(ITcpServer* pSender)override;
	virtual EnHandleResult OnClose(ITcpServer* pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)override;
	
};


