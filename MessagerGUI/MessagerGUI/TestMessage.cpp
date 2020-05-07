#include"TestMessage.h"

void TestMessage::GetHeader(char* pData, int& iLenght)
{
	pData = (char*)&mST_TestMessage.header;
	iLenght = sizeof(mST_TestMessage.header);
}

void TestMessage::GetData(char* pData, int& iLenght)
{
	pData = (char*)&mST_TestMessage.data;
	iLenght = sizeof(mST_TestMessage.data);
}
void TestMessage::SetData(const unsigned char * pData, const int iLenght)
{
	if (iLenght == sizeof(mST_TestMessage))
	{
		memcpy(&mST_TestMessage, pData, iLenght);
		delete pData;
	}
}

void TestMessage::MakeCheckNum()
{

}

std::string TestMessage::ToJson()
{
	return "{}";
}
