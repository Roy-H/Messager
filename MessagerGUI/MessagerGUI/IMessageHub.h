#pragma once
#include<memory>
#include<qDebug>
#include<HPSocket/SocketInterface.h>


class IMessageHub
{
public:	
	virtual void RecognizeMsgPackage(CONNID, const unsigned char*, const int) = 0;
	virtual void HandleData(int msgId,const unsigned char* pData,const int lenght) =0;
};