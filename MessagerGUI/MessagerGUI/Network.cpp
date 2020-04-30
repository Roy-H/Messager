#include "Network.h"

EnHandleResult TcpServer::OnPrepareListen(ITcpServer * pSender, SOCKET soListen)
{

	return HR_OK;
}

EnHandleResult TcpServer::OnAccept(ITcpServer * pSender, CONNID dwConnID, UINT_PTR soClient)
{
	return HR_OK;
}

EnHandleResult TcpServer::OnHandShake(ITcpServer * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult TcpServer::OnReceive(ITcpServer * pSender, CONNID dwConnID, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpServer::OnSend(ITcpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult TcpServer::OnShutdown(ITcpServer * pSender)
{
	return HR_OK;
}

EnHandleResult TcpServer::OnClose(ITcpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	return HR_OK;
}
