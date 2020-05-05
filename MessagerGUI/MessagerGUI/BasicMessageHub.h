#pragma once
#include "IMessageHub.h"
#include <unordered_map>
#include "MessageHelper.h"
#include <QObject>
#include"IMessage.h"
#include "MessageHelperFactory.h"
class MessageHelper;
class BasicMessageHub:public IMessageHub
{
public:
	BasicMessageHub()
	{
		MessageHelperFactory::LoadHelperDefault();
		//mMessageHelperFactoryPtr = new MessageHelperFactory();
	}
	virtual void HandleData(int msgId,const unsigned char* pData, const int iLength)override;
	
	virtual void RecognizeMsgPackage(CONNID, const unsigned char*, const int)override;
public:
	
private:
	std::unordered_map<CONNID, MessageHelper*> mHelpers;
	std::map<int,std::vector<const QObject*>> mMsgReceiver;
	//MessageHelperFactory* mMessageHelperFactoryPtr;
};