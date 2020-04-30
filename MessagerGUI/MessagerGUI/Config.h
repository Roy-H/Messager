#pragma once
class Config
{
public:
	//static char ip[10] = "127.0.0.1";
	static short sServerPort;
	static char sServerIp[10];

	static short sClientPort;
	static char sClientIp[10];
	void Test();
};
