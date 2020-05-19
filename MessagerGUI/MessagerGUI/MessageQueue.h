#pragma once
#include<mutex>
#include<memory>
#include"IMessage.h"
#define MAX_MSG_COUNT 500
class MessageQueue
{
public:
	void PushMsg(IMessage* msg_ptr);
	IMessage* PullMsg();

private:
	int mHead;
	int mTail;
	IMessage* mMsgs[MAX_MSG_COUNT];
	std::mutex mtx;
};