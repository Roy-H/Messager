#pragma once
#include<QWidget>
#include<QTableView>
#include<QDebug>
#include<QStandardItemModel>
#include"Messages.h"
class MessageTable : public QTableView
{
	Q_OBJECT
public:
	MessageTable(QStandardItemModel * model,QWidget *parent = 0);
	~MessageTable() 
	{ 
		delete mModel_ptr;
	};
public slots:
	void OnNewMessageDataCome(ST_TestMessage& msg) 
	{
		qDebug() << "123";
	};
private:
	QStandardItemModel * mModel_ptr = nullptr;
};
