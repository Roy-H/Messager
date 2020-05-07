#pragma once
#include "IMessage.h"
#include "Messages.h"

class TestMessage :public IMessage
{
public:
	TestMessage() {}
	virtual ~TestMessage() {}
	virtual void GetHeader(char* pData,int& iLenght) override;
	virtual void GetData(char* pData, int& iLenght) override;
	virtual void SetData(const unsigned char * pData,const int iLenght) override;
	virtual void MakeCheckNum() override;
	virtual std::string ToJson()override;
private:
	ST_TestMessage mST_TestMessage;
};