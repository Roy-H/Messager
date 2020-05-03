#include "MessagerGUI.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QFile>
#include "WebSockets.h"
#include "Udp.h"
#include "JsonHelper.h"

#pragma comment(lib,"D:/code/ldcsaa-HP-Socket-dev/HP-Socket/Windows/Bin/HPSocket/x64/HPSocket.lib")
int main(int argc, char *argv[])
{
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
	

	w.show();
	return a.exec();
}
