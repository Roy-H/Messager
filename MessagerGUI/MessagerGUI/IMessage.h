#pragma once
#include<string>
class IMessage
{
public:
	virtual void GetHeader(char* pData, int& iLenght) = 0;
	virtual void GetData(char* pData, int& iLenght) = 0;
	virtual void SetData(const unsigned char * pData, const int iLenght) = 0;
	virtual void MakeCheckNum() = 0;
	virtual std::string ToJson() = 0;
};
	