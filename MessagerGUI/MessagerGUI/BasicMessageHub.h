#pragma once
#include "IMessageHub.h"
#include <unordered_map>
#include "MessageHelper.h"
#include <QObject>
#include"IMessage.h"
class MessageHelper;
class BasicMessageHub:public IMessageHub
{

public:
	virtual void HandleData(CONNID dwConnID,const char* pData, const int iLength)override;
	virtual void HandleData(CONNID dwConnID, const int iLength) override;
	virtual void AddHelper(CONNID dwConnID, MessageHelper* helper) override;
	virtual void RemoveHelper(CONNID dwConnID) override;
	//注册消息信息
	virtual void Register(const QObject* qObject, int msgId) override;
	//取消注册消息信息
	virtual void Unregister(const QObject* qObject, int msgId) override;

	void NewMsgGenerate(int msgId,const IMessage& msg);
private:
	std::unordered_map<CONNID, MessageHelper*> mHelpers;
	std::map<int,std::vector<const QObject*>> mMsgReceiver;
};