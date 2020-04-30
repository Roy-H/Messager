#pragma once
#include<memory>
#include<qDebug>
class IMessageHub
{
public:
	virtual void HandleData(const char* pData,const int iLength) =0;
};