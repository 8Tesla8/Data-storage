#pragma once
#include <string.h>
#include <iostream>

using namespace std;

class Storage
{
protected:
	char model[20];
	char name[20];
	int capacity;	// ёмкость носителя
	int size;		// количество

public:
	Storage();
	virtual ~Storage();

	void setName(char* _name);
	char* getName();		//const;
	void setModel(char* _model);
	char* getModel();		//const;
	void setCapacity(int _capacity);
	int getCapacity()const;
	void setSize(int _size);
	int getSize()const;

	virtual void setExtra(int number) = 0;
	virtual int getExtra()const = 0;
};