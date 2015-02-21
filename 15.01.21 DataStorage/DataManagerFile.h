#pragma once
#include "DataManager.h"
#include <fstream>

class DataManagerFile : public DataManager
{
protected:
	virtual ~DataManagerFile()
	{
	}
	void SaveStorage(StorageManager& obj)const;

	bool SaveObj(Storage& obj)const;
	void LoadObj(Storage& obj, unsigned int& num);

	bool Load2(Storage** obj, unsigned int& num);

	bool SaveSize(const unsigned int& TypeStorage, unsigned int*& sizeStorage) const;
	bool LoadSize(unsigned int& TypeStorage, unsigned int*& sizeStorage);
};