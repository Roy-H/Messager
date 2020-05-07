#pragma once
struct node {

	int e = 1;
	char f = 0x01;
	short int a = 1;
	char b = 0x02;

};
#pragma pack(1)
struct ST_TestMessage
{
	//报文头;第一个字节标识, 第二自己报文长度,第三字节报文类型
	unsigned char header[3] = { 0x7e,0x00,0x01 };
	unsigned char data[2];
	unsigned char checkSun;
};
#pragma pop()




