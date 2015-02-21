#pragma once
#include "Storage.h"

class USB : public Storage
{
	int speed_USB;

public:
	USB();
	virtual~USB();
	void setSpeedUsb(int _speed_USB);
	int getSpeedUSB()const;

	virtual void setExtra(int number);
	virtual int getExtra()const;
};