#pragma once
#include<memory>
#include<qDebug>
#include<QObject>
#include<HPSocket/SocketInterface.h>
#include "MsgSubscriber.h"

class IMessageHub
{
public:	
	virtual void RecognizeMsgPackage(CONNID, const unsigned char*, const int) = 0;
	virtual void HandleData(int msgId,const unsigned char* pData,const int lenght) =0;
	virtual void SubscribeMsg(const int msgId, const MsgSubscriber* subscriber) = 0;

};