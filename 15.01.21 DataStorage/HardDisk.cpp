#include "harddisk.h"

HardDisk::HardDisk() :
rotational_speed(0)
{
}
HardDisk::~HardDisk()
{
}
void HardDisk::setSpeedrot(int _rotational_speed)
{
	rotational_speed = _rotational_speed;
}
int HardDisk::getSpeedrot()const
{
	return rotational_speed;
}
void HardDisk::setExtra(int number)
{
	rotational_speed = number;
}
int HardDisk::getExtra()const
{
	return rotational_speed;
}
/*
void HardDisk::Save()const
{
	FILE * f;
	fopen_s(&f, "HardDisk", "wb");
	if (f) //zapis v file
	{
		int count = 20;
		fwrite(&count, sizeof(int), 1, f); // size of array name and model

		fwrite(&name, sizeof(char), count, f);
		fwrite(&model, sizeof(char), count, f);

		fwrite(&capacity, sizeof(int), 1, f);
		fwrite(&size, sizeof(int), 1, f);
		fwrite(&rotational_speed, sizeof(int), 1, f);

		fclose(f);
	}
}
void HardDisk::Load()
{
	FILE * f;
	fopen_s(&f, "HardDisk", "rb");
	if (f) //chetenie s file
	{
		int count = 0; // size of array name and model
		fread(&count, sizeof(int), 1, f);

		fread(name, sizeof(char*), count, f);				//name
		fread(model, sizeof(char*), count, f);				//model

		fread(&capacity, sizeof(int), 1, f);				//capacity
		fread(&size, sizeof(int), 1, f);					//size
		fread(&rotational_speed, sizeof(int), 1, f);		//speed

		fclose(f);
	}
}
*/