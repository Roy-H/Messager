#pragma once
#include<memory>
#include<qDebug>
#include<HPSocket.h>
#include<HPTypeDef.h>
#include<QObject>
class MessageHelper;
class IMessageHub
{
public:
	virtual void HandleData(CONNID,const char*,const int ) =0;
	virtual void HandleData(CONNID , const int ) = 0;
	virtual void AddHelper(CONNID , MessageHelper* ) = 0;
	virtual void RemoveHelper(CONNID ) = 0;
	//注册消息信息
	virtual void Register(const QObject* qObject, int msgId) =0;
	//取消注册消息信息
	virtual void Unregister(const QObject* qObject, int msgId) =0;
};