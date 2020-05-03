#include "TableControl.h"
#include"MessageHelper.h"
MessageTable::MessageTable(QStandardItemModel* model ,QWidget *parent)
	: QTableView(parent), mModel_ptr(model)
{
	this->setModel(mModel_ptr);
	//connect(,SIGNAL(MessageHelper::GenerateMessage()) , this,SLOT(MessageTable::OnNewMessageDataCome()));
}