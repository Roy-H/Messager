#pragma once

#include"IMessageHelper.h"
class MessageHelper:public IMessageHelper
{
public:
	virtual void GenerateMessage() override;

};