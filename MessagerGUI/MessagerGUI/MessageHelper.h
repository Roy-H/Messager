#pragma once
#include<QObject>
#include"IMessageHelper.h"
//#include "BasicMessageHub.h"
class BasicMessageHub;
class MessageHelper:public QObject,public IMessageHelper
{
	Q_OBJECT
public:
	MessageHelper(std::shared_ptr<BasicMessageHub> hub):mMsgHub(hub)
	{

	}
	virtual void GenerateMessage() override;
	virtual int GetMsgId()override;
	virtual void SetMsgId(int msgId) override;
signals:
	void OnMessageCome();
private:
	std::shared_ptr<BasicMessageHub> mMsgHub;
	int mMsgId;
};