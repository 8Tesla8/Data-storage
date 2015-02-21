#pragma once
#include "Storage.h"
#include "DVD.h"
#include "HardDisk.h"
#include "USB.h"
#include "StorageManager.h"

class DataManager
{	
protected:
	friend class StorageManager;
	virtual ~DataManager()
	{
	}
	virtual void SaveStorage(StorageManager& obj)const = 0;

	virtual bool SaveObj(Storage& obj) const = 0;
	virtual void LoadObj(Storage& obj, unsigned int& num) = 0;

	virtual bool Load2(Storage** obj, unsigned int& num) = 0;

	virtual bool SaveSize(const unsigned int& TypeStorage, unsigned int*& sizeStorage) const = 0;
	virtual bool LoadSize(unsigned int& TypeStorage, unsigned int*& sizeStorage) = 0;
};