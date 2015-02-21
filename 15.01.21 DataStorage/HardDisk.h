#pragma once
#include "Storage.h"

class HardDisk : public Storage
{
	int	rotational_speed;
public:
	HardDisk();
	virtual ~HardDisk();
	void setSpeedrot(int _rotational_speed);
	int getSpeedrot()const;

	virtual void setExtra(int number);
	virtual int getExtra()const;
};