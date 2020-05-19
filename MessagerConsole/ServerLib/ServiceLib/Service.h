#pragma once

#include "servicelib_global.h"

class SERVICELIB_EXPORT Service
{
public:
	Service();
	~Service();
	void Start();
	void Stop();
	void Pause();
	void Resume();
	Service(Service&) = delete;
	void operator =(Service &) = delete;

private:
	void InitResource();
	void ReleaseResource();

};
