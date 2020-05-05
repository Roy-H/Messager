#include "MessageHelper.h"


#include <QDebug> 
void MessageHelper::HandleMessage(const unsigned char* pData, const int len)
{
	qDebug() << "GenerateMessage MessageHelper";
	emit OnMessageCome();
}

void MessageHelper::SetMsgId(int msgId)
{
	mMsgId = msgId;
}

int MessageHelper::GetMsgId()
{
	return mMsgId;
}

void TestMessageHelper::HandleMessage(const unsigned char* pData, const int len)
{
	qDebug() << "GenerateMessage TestMessageHelper";
	emit OnMessageCome();
}
