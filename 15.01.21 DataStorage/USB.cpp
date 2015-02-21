#include "USB.h"

USB::USB() :
speed_USB(0)
{
}
USB::~USB()
{
}
void USB::setSpeedUsb(int _speed_USB)
{
	speed_USB = _speed_USB;
}
int USB::getSpeedUSB()const
{
	return speed_USB;
}
void USB::setExtra(int number)
{
	speed_USB = number;
}
int USB::getExtra()const
{
	return speed_USB;
}
/*
void USB::Save()const
{
	FILE * f;
	fopen_s(&f, "USB", "wb");
	if (f) //zapis v file
	{
		int count = 20;
		fwrite(&count, sizeof(int), 1, f); // size of array name and model

		fwrite(&name, sizeof(char*), count, f);
		fwrite(&model, sizeof(char*), count, f);

		fwrite(&capacity, sizeof(int), 1, f);
		fwrite(&size, sizeof(int), 1, f);
		fwrite(&speed_USB, sizeof(int), 1, f);

		fclose(f);
	}
}
void USB::Load()
{
	FILE * f;
	fopen_s(&f, "USB", "rb");
	if (f) //chetenie s file
	{
		int count = 0; // size of array name and model
		fread(&count, sizeof(int), 1, f);

		fread(name, sizeof(char*), count, f);		//name
		fread(model, sizeof(char*), count, f);		//model

		fread(&capacity, sizeof(int), 1, f);		//capacity
		fread(&size, sizeof(int), 1, f);			//size
		fread(&speed_USB, sizeof(int), 1, f);		//speed

		fclose(f);
	}
}
*/