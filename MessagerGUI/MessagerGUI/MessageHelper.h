#pragma once
#include<QObject>
#include"IMessageHelper.h"

class MessageHelper:public QObject,public IMessageHelper
{
	Q_OBJECT
public:
	typedef std::shared_ptr<MessageHelper> ptr;
	MessageHelper() {}
	virtual IMessage* HandleMessage(const unsigned char*, const int ) override;
	virtual int GetMsgId()override;
	virtual void SetMsgId(int msgId) override;
protected:
	int mMsgId;
};


class TestMessageHelper :public MessageHelper
{
	Q_OBJECT
public:
	virtual IMessage* HandleMessage(const unsigned char*, const int ) override;
signals:
	void OnMessageCome(IMessage*);
};