#include "MessagerGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MessagerGUI w;
	w.show();
	return a.exec();
}
