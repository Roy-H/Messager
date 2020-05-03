#pragma once
#include "IMessageHub.h"
#include <unordered_map>
class BasicMessageHub:public IMessageHub
{
public:
	virtual void HandleData(int dwConnID,const char* pData, const int iLength)override;
	virtual void HandleData(int dwConnID, const int iLength) override;
private:
	//std::unordered_map<dwConnID,>
};