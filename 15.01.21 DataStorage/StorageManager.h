#pragma once
#include "Storage.h"
#include "DVD.h"
#include "HardDisk.h"
#include "USB.h"
#include "InOut.h"
#include "InOutConsole.h"
#include "DataManager.h"	
#include "DataManagerFile.h"

class StorageManager
{
	InOut *methodInOut;
	DataManager *methodSL;			// error here
	Storage **ptr;		
	unsigned int TypeStorage;
	unsigned int* sizeStorage;
	unsigned int* oldSizeStorage;
	unsigned int sizeAll; 
	unsigned int oldSizeAll;
	unsigned int find;
	int* findIndex;

	void Create();
	void Add();
	void Serch();
	void Delete();
	void Print()const;
	void Edit();
	void Sorting();
	void Save();
	void Load();

public:
	StorageManager();
	~StorageManager();
	void Menu();
};