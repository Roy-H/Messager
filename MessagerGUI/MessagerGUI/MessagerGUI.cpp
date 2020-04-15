#include "MessagerGUI.h"


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
	
	connect(ui.com_send_btn, SIGNAL(clicked()),this,SLOT(OnComSendBtnClicked()));
	m_Com_ptr = std::make_shared<Com>(Com::Find(ui.comboBox->currentText()));
	m_UdpSocket_ptr = std::make_shared<UdpSocket>();
	connect(ui.udp_send_btn, SIGNAL(clicked()), this, SLOT(OnUdpSendBtnClicked()));

	m_TcpSocket_ptr = std::make_shared<TcpSocket>();
	connect(ui.tcp_send_btn, SIGNAL(clicked()), this, SLOT(OnTcpSendBtnClicked()));
	ui.tableView.
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
