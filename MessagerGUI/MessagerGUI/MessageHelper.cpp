#include "MessageHelper.h"
#include "IMessage.h"
#include "TestMessage.h"
#include <QDebug> 


void MessageHelper::SetMsgId(int msgId)
{
	mMsgId = msgId;
}

IMessage* TestMessageHelper::HandleMessage(const unsigned char * pData, const int len)
{
	auto pMsg = new TestMessage();
	pMsg->SetData(pData, len);
	qDebug() << "GenerateMessage TestMessageHelper";
	return  pMsg;
}

IMessage * MessageHelper::HandleMessage(const unsigned char * pData, const int len)
{
	
	qDebug() << "GenerateMessage MessageHelper";
	return nullptr;
}

int MessageHelper::GetMsgId()
{
	return mMsgId;
}

