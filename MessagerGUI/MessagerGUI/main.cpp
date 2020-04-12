#include "MessagerGUI.h"
#include <QtWidgets/QApplication>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MessagerGUI w;

	
	
	w.show();
	return a.exec();
}
