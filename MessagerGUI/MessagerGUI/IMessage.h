#pragma once
class IMessage
{
public:
	virtual void GetHeader(char* pData, int& iLenght) = 0;
	virtual void GetData(char* pData, int& iLenght) = 0;
	virtual void MakeCheckNum() = 0;
};
	