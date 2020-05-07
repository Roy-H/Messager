#pragma once
#include<QObject>
#include"IMessage.h"
class MsgSubscriber:public QObject
{
	Q_OBJECT
public:
	MsgSubscriber(QObject* parent = nullptr) :QObject(parent) {}
public slots:
	void OnNewMessageCome(IMessage* newMsg);
};