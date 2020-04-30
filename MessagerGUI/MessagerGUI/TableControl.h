#pragma once
#include<QWidget>
#include<QTableView>
#include<QStandardItemModel>
class MessageTable : public QTableView
{
	Q_OBJECT
public:
	MessageTable(QStandardItemModel * model,QWidget *parent = 0);
	~MessageTable() 
	{ 
		delete mModel_ptr;
	};
private:
	QStandardItemModel * mModel_ptr = nullptr;
};
