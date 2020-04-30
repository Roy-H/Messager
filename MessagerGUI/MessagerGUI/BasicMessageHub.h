#pragma once
#include "IMessageHub.h"
class BasicMessageHub:public IMessageHub
{
public:
	virtual void HandleData(const char* pData, const int iLength)override;
};