#include "MessagerGUI.h"

MessagerGUI::MessagerGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	connect(ui.com_send_btn, SIGNAL(clicked()),this,SLOT(OnComSendBtnClicked()));
	m_Com_ptr = std::make_shared<Com>(Com::Find(ui.comboBox->currentText()));
	m_UdpSocket_ptr = std::make_shared<UdpSocket>();
	connect(ui.udp_send_btn, SIGNAL(clicked()), this, SLOT(OnUdpSendBtnClicked()));

	m_TcpSocket_ptr = std::make_shared<TcpSocket>();
	connect(ui.tcp_send_btn, SIGNAL(clicked()), this, SLOT(OnTcpSendBtnClicked()));
}

void MessagerGUI::OnComSendBtnClicked()
{
	QString str = ui.com_input->text();
	qDebug() << str << "\n";
	m_Com_ptr->Send(str);
}

void MessagerGUI::OnUdpSendBtnClicked()
{
	QString str = ui.udp_input->text();
	qDebug() << str << "\n";
	m_UdpSocket_ptr->Send(str);
}

void MessagerGUI::OnTcpSendBtnClicked()
{
	QString str = ui.tcp_input->text();
	qDebug() << str << "\n";
	//m_TcpSocket_ptr->Send(str);
	m_TcpSocket_ptr->Connect();
}
