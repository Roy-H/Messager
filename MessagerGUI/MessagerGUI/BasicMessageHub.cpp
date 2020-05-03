#include"BasicMessageHub.h"

void BasicMessageHub::HandleData(CONNID dwConnID, const char * pData, const int iLength)
{
	if (mHelpers.find(dwConnID)!= mHelpers.end())
	{
		(*mHelpers[dwConnID]).GenerateMessage();
	}
	return;
}

void BasicMessageHub::HandleData(CONNID dwConnID, const int iLength)
{
	return;
}

void BasicMessageHub::AddHelper(CONNID dwConnID, MessageHelper* helper)
{
	//没有出现添加
	if(mHelpers.find(dwConnID) == mHelpers.end())
		mHelpers[dwConnID] = helper;
}

void BasicMessageHub::RemoveHelper(CONNID dwConnID)
{
	auto pos = mHelpers.find(dwConnID);
	if (pos != mHelpers.end())
	{
		IMessageHelper* p = mHelpers[dwConnID];
		mHelpers.erase(dwConnID);
		delete p;
	}
}

void BasicMessageHub::Register(const QObject * qObject, int msgId)
{
	mMsgReceiver[msgId].push_back(qObject);
}

void BasicMessageHub::Unregister(const QObject * qObject, int msgId)
{

	for (auto i = mMsgReceiver[msgId].begin(); i != mMsgReceiver[msgId].end(); i++)
	{
		if (*i == qObject)
		{
			mMsgReceiver[msgId].erase(i);
			break;
		}
	}
	
	
}

void BasicMessageHub::NewMsgGenerate(int msgId, const IMessage & msg)
{
	//emit(mMsgReceiver[msgId])
}

