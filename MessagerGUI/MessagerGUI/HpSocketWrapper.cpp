#include "HpSocketWrapper.h"
#include "HPTypeDef.h"
#include <QDebug>

EnHandleResult CListenerImpl::OnPrepareListen(ITcpServer * pSender, SOCKET soListen)
{
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetListenAddress(szAddress, iAddressLen, usPort);
	qDebug() << "ip:" << szAddress << " ip length:" << iAddressLen << " port:" << usPort;
	
	//::PostOnPrepareListen(szAddress, usPort);

	return HR_OK;
}

EnHandleResult CListenerImpl::OnAccept(ITcpServer * pSender, CONNID dwConnID, UINT_PTR soClient)
{
	BOOL bPass = TRUE;
	TCHAR szAddress[50];
	int iAddressLen = sizeof(szAddress) / sizeof(TCHAR);
	USHORT usPort;

	pSender->GetRemoteAddress(dwConnID, szAddress, iAddressLen, usPort);

	//if (!g_app_arg.reject_addr.IsEmpty())
	//{
	//	if (g_app_arg.reject_addr.CompareNoCase(szAddress) == 0)
	//		bPass = FALSE;
	//}

	//::PostOnAccept(dwConnID, szAddress, usPort, bPass);

	//if (bPass) ::CreatePkgInfo(pSender, dwConnID);

	return bPass ? HR_OK : HR_ERROR;
}

EnHandleResult CListenerImpl::OnHandShake(ITcpServer * pSender, CONNID dwConnID)
{
	return HR_OK;
}

EnHandleResult CListenerImpl::OnReceive(ITcpServer * pSender, CONNID dwConnID, int iLength)
{
	//TPkgInfo* pInfo = ::FindPkgInfo(pSender, dwConnID);
	ITcpPullServer* pServer = ITcpPullServer::FromS(pSender);

	int sizeofPkg = 10;

	if (sizeofPkg >0)
	{
		int required = sizeofPkg;
		int remain = iLength;

		while (remain >= required)
		{
			remain -= required;
			//CBufferPtr buffer(required);
			BYTE* buffer = (BYTE*)malloc(required);
			EnFetchResult result = pServer->Fetch(dwConnID, buffer, required);

			if (result == FR_OK)
			{
				//pInfo->is_header = !pInfo->is_header;
				//pInfo->length = required;
				pSender->Send(dwConnID, buffer, sizeofPkg);
			}
			free(buffer);
		}
	}

	return HR_OK;
}

EnHandleResult CListenerImpl::OnSend(ITcpServer * pSender, CONNID dwConnID, const BYTE * pData, int iLength)
{
	return HR_OK;
}

EnHandleResult CListenerImpl::OnClose(ITcpServer * pSender, CONNID dwConnID, EnSocketOperation enOperation, int iErrorCode)
{
	return HR_OK;
}

EnHandleResult CListenerImpl::OnShutdown(ITcpServer * pSender)
{
	return HR_OK;
}

