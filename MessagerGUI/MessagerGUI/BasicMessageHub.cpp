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
