#pragma once
#include "Storage.h"
#include "DVD.h"
#include "HardDisk.h"
#include "USB.h"

class InOut
{
	friend class StorageManager;
protected:
	virtual ~InOut()
	{
	}
	virtual void ChoiceMenu(unsigned int& typeStorage, unsigned int *massif, int &choice) = 0;
	virtual void SerchMenu(int& choice, char* buff) = 0;
	virtual void WhichMenu(unsigned int& find, int& which, bool or) = 0;
	virtual void SortingMenu(int& choice) = 0;
	virtual void InputData(Storage& obj) = 0;
	virtual void OutputData(Storage& obj, unsigned int& count) const = 0;
	virtual void InfoSL() const = 0;
};