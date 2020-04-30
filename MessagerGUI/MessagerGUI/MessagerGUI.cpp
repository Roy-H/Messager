#include "MessagerGUI.h"
#include"WebSockets.h"
#include<QStandardItemModel>
#include"TableControl.h"
class TableModel : public QAbstractTableModel
{
	Q_OBJECT

public:

	int rowCount(const QModelIndex & = QModelIndex()) const override
	{
		return 200;
	}

	int columnCount(const QModelIndex & = QModelIndex()) const override
	{
		return 200;
	}

	QVariant data(const QModelIndex &index, int role) const override
	{
		switch (role) {
		case Qt::DisplayRole:
			return QString("%1, %2").arg(index.column()).arg(index.row());
		default:
			break;
		}

		return QVariant();
	}

	QHash<int, QByteArray> roleNames() const override
	{
		return { { Qt::DisplayRole, "display" } };
	}
};


MessagerGUI::MessagerGUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	model = new QStandardItemModel(nullptr);

	model->setColumnCount(3);
	model->setHeaderData(0, Qt::Horizontal, "name");
	model->setHeaderData(1, Qt::Horizontal, "age");
	model->setHeaderData(2, Qt::Horizontal, "gender");
	
	model->setRowCount(3);
	model->setHeaderData(0, Qt::Vertical, "item1");
	model->setHeaderData(1, Qt::Vertical, "item2");
	model->setHeaderData(2, Qt::Vertical, "item3");
	model->setItem(0, 0, new QStandardItem("zhangshan"));
	model->setItem(0, 1, new QStandardItem("3"));
	model->setItem(0, 2, new QStandardItem("boy"));

	auto tableView = new MessageTable(model, ui.groupBox_info);
	QSize size;
	size.setHeight( 500);
	size.setWidth(1000);
	tableView->setMinimumSize(size);
	connect(ui.com_send_btn, SIGNAL(clicked()),this,SLOT(OnComSendBtnClicked()));
	//m_Com_ptr = std::make_shared<Com>(Com::Find(ui.comboBox->currentText()));
	m_UdpSocket_ptr = std::make_shared<UdpSocket>();
	connect(ui.udp_send_btn, SIGNAL(clicked()), this, SLOT(OnUdpSendBtnClicked()));

	m_TcpSocket_ptr = std::make_shared<TcpSocket>();
	connect(ui.tcp_send_btn, SIGNAL(clicked()), this, SLOT(OnTcpSendBtnClicked()));
	
	connect(ui.websock_send_btn,SIGNAL(clicked()),this,SLOT(OnWebSockSendBtnClicked()));
	connect(ui.websock_server_setup, SIGNAL(clicked()), this, SLOT(OnWebSockServerSetupBtnClicked()));
}

void MessagerGUI::OnWebSockSendBtnClicked()
{
	/*if (!m_WebSock_ptr)
		return;*/
	
}
void MessagerGUI::OnWebSockServerSetupBtnClicked()
{
	/*if (!m_WebSock_ptr)
	{*/
		/*QMessageBox::about(NULL, "error", "server already exist");
		return;*/
	//}
	//m_WebSock_ptr = std::make_shared<WebSock>(1234);
	m_WebSock_ptr = new WebSock(1234);
	QMessageBox::about(NULL, "ok", "create websock on 6666");

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
