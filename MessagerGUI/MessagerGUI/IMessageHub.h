#pragma once
#include<memory>
#include<qDebug>
#include<HPSocket.h>
#include<HPTypeDef.h>
class MessageHelper;
class IMessageHub
{
public:
	virtual void HandleData(CONNID,const char*,const int ) =0;
	virtual void HandleData(CONNID , const int ) = 0;
	virtual void AddHelper(CONNID , MessageHelper* ) = 0;
	virtual void RemoveHelper(CONNID ) = 0;
};