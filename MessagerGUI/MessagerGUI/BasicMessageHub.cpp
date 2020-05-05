#include"BasicMessageHub.h"
#include "Messages.h"

void BasicMessageHub::HandleData(int msgId, const unsigned char * pData, const int iLength)
{
	auto helper = MessageHelperFactory::CreateHelper(msgId);
	if (helper == nullptr)
	{
		qDebug() << "there is no match helper for id:" << msgId;
		return;
	}
	helper->HandleMessage(pData, iLength);
}

//接收到数据第一步要做的
void BasicMessageHub::RecognizeMsgPackage(CONNID connID, const unsigned char *pData, const int len)
{
	HandleData(1, pData, len);
}


//template<class T>
//int BasicMessageHub::ProcessMsg_1(const unsigned char* pdata, const int len, void* result)
//{
//	if (len != sizeof(T))
//	{
//		qDebug() << "size of pkg is not match, this pkg will be dropped";
//		delete pdata;
//		return 0;
//	}
//	T* pPkg = new T();
//	memset(pPkg, 0, sizeof(T));
//	memcpy(pPkg, pdata, sizeof(T));
//	result = pPkg;
//	delete pdata;
//	return 1;
//}
