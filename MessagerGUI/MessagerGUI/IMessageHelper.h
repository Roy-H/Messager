#pragma once
#include "IMessage.h"
class IMessageHelper
{
public:
 	virtual  IMessage* HandleMessage(const unsigned char*, const int ) = 0;
	virtual int GetMsgId() = 0;
	virtual void SetMsgId(int msgId) = 0;
};