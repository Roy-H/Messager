#include "MessagerGUI.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QFile>
#include "WebSockets.h"
#include "Udp.h"
#include "JsonHelper.h"
#include "BasicMessageHub.h"
#include "MsgSubscriber.h"
#include "Service.h"

#pragma comment(lib,"D:/code/ldcsaa-HP-Socket-dev/HP-Socket/Windows/Bin/HPSocket/x64/HPSocket.lib")
//#pragma comment(lib,"D:/code/Cpp/Messager/MessagerConsole/x64/Debug/ServiceLib.lib")
int main(int argc, char *argv[])
{
	std::shared_ptr<Service> ptr = std::make_shared<Service>();
	ptr->Start();
	QApplication a(argc, argv);
	MessagerGUI w;

	//QFile qss(":/MessagerGUI/black");
	QFile qss(":/MessagerGUI/black2.qss");
	
	if (qss.open(QFile::ReadOnly))
	{
		qDebug("open success");

		QString style = QLatin1String(qss.readAll());

		a.setStyleSheet(style);

		qss.close();
	}
	else
	{
		qDebug("Open failed");
	}
	
	JsonHelper jsonHelper;
	jsonHelper.Test();
	
	IMessageHub* hub = new BasicMessageHub();
	MsgSubscriber* mSubscriber = new MsgSubscriber();
	hub->SubscribeMsg(1, mSubscriber);
	Udp udp(hub);
	udp.StartServer();
	w.show();

	
	return a.exec();
}
