#include "MessagerGUI.h"

MessagerGUI::MessagerGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	connect(ui.pushButton, SIGNAL(clicked()),this,SLOT(OnSendBtnClicked()));
	m_Com_ptr = std::make_shared<Com>(Com::Find(ui.comboBox->currentText()));
}

void MessagerGUI::OnSendBtnClicked()
{
	QString str = ui.lineEdit->text();
	qDebug() << str << "\n";
	m_Com_ptr->Send(str);
}
