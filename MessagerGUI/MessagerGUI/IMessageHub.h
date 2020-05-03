#pragma once
#include<memory>
#include<qDebug>

class IMessageHub
{
public:
	virtual void HandleData(int dwConnID,const char* pData,const int iLength) =0;
	virtual void HandleData(int dwConnID, const int iLength) = 0;
};