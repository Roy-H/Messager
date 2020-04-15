#include "MessagerGUI.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include<QFile>

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
	
	w.show();
	return a.exec();
}
