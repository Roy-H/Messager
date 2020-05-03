#include "MessageHelper.h"
#include <QDebug> 
void MessageHelper::GenerateMessage()
{
	qDebug() << "GenerateMessage";
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
