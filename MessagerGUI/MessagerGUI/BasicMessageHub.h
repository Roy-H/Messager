#pragma once
#include "IMessageHub.h"
#include <unordered_map>
#include "MessageHelper.h"
class MessageHelper;
class BasicMessageHub:public IMessageHub
{
public:
	virtual void HandleData(CONNID dwConnID,const char* pData, const int iLength)override;
	virtual void HandleData(CONNID dwConnID, const int iLength) override;
	virtual void AddHelper(CONNID dwConnID, MessageHelper* helper) override;
	virtual void RemoveHelper(CONNID dwConnID) override;

	
private:
	std::unordered_map<CONNID, MessageHelper*> mHelpers;
};