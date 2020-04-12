#pragma once

#include <QtWidgets/QWidget>
#include "ui_MessagerGUI.h"
#include"Com.h"

class MessagerGUI : public QWidget
{
	Q_OBJECT

public:
	MessagerGUI(QWidget *parent = Q_NULLPTR);
public slots:
	void OnSendBtnClicked();
private:
	Ui::MessagerGUIClass ui;
	std::shared_ptr<Com> m_Com_ptr;
};
