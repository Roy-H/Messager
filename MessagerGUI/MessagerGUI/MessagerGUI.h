#pragma once

#include <QtWidgets/QWidget>
#include "ui_MessagerGUI.h"

class MessagerGUI : public QWidget
{
	Q_OBJECT

public:
	MessagerGUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::MessagerGUIClass ui;
};
