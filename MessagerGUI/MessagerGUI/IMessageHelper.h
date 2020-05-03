#pragma once
class IMessageHelper
{
public:
 	virtual void GenerateMessage() = 0;
	virtual int GetMsgId() = 0;
	virtual void SetMsgId(int msgId) = 0;
};