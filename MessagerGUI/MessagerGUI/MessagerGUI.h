#pragma once

#include <QtWidgets/QWidget>
#include "ui_MessagerGUI.h"
#include"Com.h"
#include"Socket.h"
#include"WebSockets.h"

class MessagerGUI : public QWidget
{
	Q_OBJECT

public:
	MessagerGUI(QWidget *parent = Q_NULLPTR);
public slots:
	void OnComSendBtnClicked();
	void OnWebSockSendBtnClicked();
	void OnWebSockServerSetupBtnClicked();
	void OnUdpSendBtnClicked();
	void OnTcpSendBtnClicked();
private:
	Ui::MessagerGUIClass ui;
	std::shared_ptr<Com> m_Com_ptr;
	std::shared_ptr<UdpSocket> m_UdpSocket_ptr;
	std::shared_ptr<TcpSocket> m_TcpSocket_ptr;
	//std::shared_ptr<WebSock> m_WebSock_ptr;
	WebSock*m_WebSock_ptr;
};
