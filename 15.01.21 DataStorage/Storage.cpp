#include "Storage.h"

Storage::Storage() :
capacity(0),
size(0)
{
	for (unsigned int i = 0; i < 20; ++i)
	{
		name[i] = 0U;
		model[i] = 0U;
	}

	strcpy_s(name, sizeof(name), "Name\0");
	strcpy_s(model, sizeof(model), "Model\0");
}
Storage::~Storage()
{
}
void Storage::setName(char*_name)
{
	strcpy_s(name, strlen(_name) + 1U, _name);
}
char* Storage::getName()
{
	return name;
}
void Storage::setModel(char*_model)
{
	strcpy_s(model, strlen(_model) + 1U, _model);
}
char* Storage::getModel()
{
	return model;
}
void Storage::setCapacity(int _capacity)
{
	capacity = _capacity;
}
int Storage::getCapacity()const
{
	return capacity;
}
void Storage::setSize(int _size)
{
	size = _size;
}
int Storage::getSize()const
{
	return size;
}