#include "MessageQueue.h"

void MessageQueue::PushMsg(IMessage * msg_ptr)
{
	std::lock_guard<std::mutex> mt(mtx);
	if (mTail == MAX_MSG_COUNT)
		return;
	mMsgs[mTail] = msg_ptr;
	mTail++;
}

IMessage * MessageQueue::PullMsg()
{
	std::lock_guard<std::mutex> mt(mtx);
	if (mTail == mHead)
		return nullptr;

	return mMsgs[mTail];
}
