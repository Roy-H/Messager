#include "TableControl.h"

MessageTable::MessageTable(QStandardItemModel* model ,QWidget *parent)
	: QTableView(parent), mModel_ptr(model)
{
	this->setModel(mModel_ptr);
}