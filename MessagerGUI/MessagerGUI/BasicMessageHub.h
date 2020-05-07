#pragma once
#include "IMessageHub.h"
//#include <unordered_map>
#include <map>
#include <vector>
#include "MessageHelper.h"
#include <QObject>
#include"IMessage.h"
#include "MessageHelperFactory.h"
#include "MsgSubscriber.h"

class MsgSignals :public QObject
{
	Q_OBJECT
public:
	void BroadcastTestMessage(IMessage* msg)
	{
		emit OnTestMessageCome(msg);
	}
	void BroadcastTestMessage2(IMessage* msg)
	{
		emit OnTestMessage2Come(msg);
	}
signals:
	void OnTestMessageCome(IMessage* msg);
	void OnTestMessage2Come(IMessage* msg);
};

class BasicMessageHub:public IMessageHub
{
public:
	BasicMessageHub()
	{
		//MessageHelperFactory::LoadHelperDefault();
		mMsgSignals = new MsgSignals();
		//mMessageHelperFactoryPtr = new MessageHelperFactory();
	}
	virtual ~BasicMessageHub()
	{
		delete mMsgSignals;
	}
	virtual void HandleData(int msgId,const unsigned char* pData, const int iLength)override;
	
	virtual void RecognizeMsgPackage(CONNID, const unsigned char*, const int)override;

	virtual void SubscribeMsg(const int msgId, const MsgSubscriber* subscriber)override;
	
private:
	std::map<int, std::vector<MsgSubscriber*>> mSubscribers;
	MsgSignals* mMsgSignals = nullptr;
};