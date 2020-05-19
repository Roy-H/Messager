#include "Service.h"
#include <iostream>
#include <QDebug>
Service::Service()
{
}

Service::~Service()
{
	Stop();
}

void Service::Start()
{
	InitResource();
	std::cout << "Service Started..." << std::endl;
	qDebug() << "Service Started...";
}

void Service::Stop()
{
	ReleaseResource();
	std::cout << "Service Stoped..." << std::endl;
	qDebug() << "Service Stoped...";
}

void Service::Pause()
{
}

void Service::Resume()
{
}

void Service::InitResource()
{
}

void Service::ReleaseResource()
{
}
