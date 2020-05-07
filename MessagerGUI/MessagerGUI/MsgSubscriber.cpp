#include"MsgSubscriber.h"
#include <QDebug>
#include<Messages.h>

void MsgSubscriber::OnNewMessageCome(IMessage* msgPtr)
{
	char* pData;
	int len;
	msgPtr->GetData(pData,len);
	

	qDebug() << *pData;
}