#pragma once

#include <QtCore/QObject>
#include <QtCore/QList>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)
QT_FORWARD_DECLARE_CLASS(QString)
class WebSock:public QObject
{
	Q_OBJECT
public:
	 WebSock(quint16 port, QObject *parent = nullptr);
	~WebSock()override;

private slots:
	void processMessage(const QString &message);
	void socketDisconnected();
	void onNewConnection();
	
private:
	QWebSocketServer * m_pWebSocketServer;
	QList<QWebSocket *> m_clients;

};