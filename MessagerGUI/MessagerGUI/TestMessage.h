#pragma once
#include "IMessage.h"
#include "Messages.h"

class TestMessage :public IMessage
{
public:
	TestMessage(ST_TestMessage t_st) :mST_TestMessage(t_st) {}
	virtual void GetHeader(char* pData,int& iLenght) override;
	virtual void GetData(char* pData, int& iLenght) override;
	virtual void MakeCheckNum() override;

private:
	ST_TestMessage mST_TestMessage;
};