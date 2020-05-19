#include"BasicMessageHub.h"
#include "Messages.h"
#include <thread>
#include<iostream>

/*
void BasicMessageHub::operator()(int msgId, const unsigned char * pData, const int lenght)
{
	std::cout<<"thread id:" << std::this_thread::get_id() << std::endl;
	auto helper = std::make_shared<TestMessageHelper>();// new MessageHelper();
	if (!helper)
	{
		qDebug() << "there is no match helper for id:" << msgId;
		return;
	}
	IMessage* msg_ptr = nullptr;
	msg_ptr = helper->HandleMessage(pData, lenght);
	mMsgSignals->BroadcastTestMessage(msg_ptr);
}*/

void BasicMessageHub::HandleData(int msgId, const unsigned char * pData, const int iLength)
{
	//auto helper = MessageHelperFactory::CreateHelper(msgId);
	auto helper = std::make_shared<TestMessageHelper>();// new MessageHelper();
	if (!helper)
	{
		qDebug() << "there is no match helper for id:" << msgId;
		return;
	}
	IMessage* msg_ptr = nullptr;
	msg_ptr = helper->HandleMessage(pData, iLength);
	mMsgSignals->BroadcastTestMessage(msg_ptr);
}

//接收到数据第一步要做的
void BasicMessageHub::RecognizeMsgPackage(CONNID connID, const unsigned char *pData, const int len)
{
	qDebug() << "id:" << connID<<" pkg_len:"<< len;
	delete pData;
	//HandleData(1, pData, len);
}

void BasicMessageHub::SubscribeMsg(const int msgId, const MsgSubscriber * subscriber)
{
	if (!mMsgSignals)
		return;
	if (msgId == 1)
	{
		mMsgSignals->connect(mMsgSignals, SIGNAL(OnTestMessageCome(IMessage*)), subscriber, SLOT(OnNewMessageCome(IMessage*)));
	}
	else if (msgId == 2)
	{
		mMsgSignals->connect(mMsgSignals, SIGNAL(OnTestMessage2Come(IMessage*)), subscriber, SLOT(OnNewMessageCome(IMessage*)));
	}
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
