#pragma once
#include "DataManagerFile.h"
#include <stdlib.h>

void DataManagerFile::SaveStorage(StorageManager& obj)const
{
	/*
	ofstream out("sizestorage.txt");
	if (out.is_open())
	{
	out << obj.TypeStorage << ' ';
	for (unsigned int i = 0U; i < obj.TypeStorage; ++i)
	{
	out << obj.sizeStorage[i] << ' ';
	}
	out << endl;
	out.close();
	}
	*/
}
bool DataManagerFile::SaveObj(Storage& obj)const
{
	ofstream out("storage.txt", ios::out | ios::app); 	

	if (out.is_open())
	{
		out << obj.getName() << '\n';
		out << obj.getModel() << '\n';
		out << obj.getCapacity() << '\n';
		out << obj.getSize() << '\n';
		out << obj.getExtra() << '\n';
		//out << endl;
		
		out.close();
	}
	else
	{
		return false;
	}

	return true;
	/*
	http://cppstudio.com/post/446/
	ios::in 		открыть файл для чтения
	ios::out 		открыть файл для записи
	ios::ate 		при открытии переместить указатель в конец файла
	ios::app 		открыть файл для записи в конец файла
	ios::trunc 		удалить содержимое файла, если он существует
	ios::binary 	открытие файла в двоичном режиме
	ios::nocreate	не выполнять операцию открытия файла, если он не существует;
	ios::noreplace  не открывать существующий файл.

	ofstream по умолчанию(default) ios::out | ios::trunc
	ifstream по умолчанию(default) ios::in

	флаги ate и app по описанию очень похожи, они оба перемещают указатель в конец файла, но флаг app позволяет производить запись, 
	только в конец файла, а флаг ate просто переставляет флаг в конец файла и не ограничивает места записи.
	*/
}
bool DataManagerFile::Load2(Storage** obj, unsigned int& count)
{
	ifstream in("storage.txt");

	if (in.is_open())
	{
		for (unsigned int i = 0U; i < count; ++i)
		{
			char buff[20] = {};
			int number = 0;

			in.getline(buff, 20);
			obj[i]->setName(buff);

			in.getline(buff, 20);
			(obj[i])->setModel(buff);
			
			//in >> number;
			in.getline(buff, 20);
			number = atoi(buff);
			obj[i]->setCapacity(number);

			//in >> number;
			in.getline(buff, 20);
			number = atoi(buff);
			obj[i]->setSize(number);

			//in >> number;
			in.getline(buff, 20);
			number = atoi(buff);
			obj[i]->setExtra(number);
		}

		in.close();
	}
	else
	{
		return false;
	}

	return true;
}
void DataManagerFile::LoadObj(Storage& obj, unsigned int& fileDeposition)
{
	ifstream in("storage.txt");

	if (in.is_open())
	{
		in.seekg(fileDeposition, ios::beg);

		char buff[20] = {};
		int number = 0, count=0;

		in.getline(buff, 20);
		//in >> buff;		
		obj.setName(buff);
		for (count = 0; count < 20 && buff[count] != 0; ++count) { } //считываю смещение в файле
		fileDeposition += count + 1;

		//in >> buff;
		in.getline(buff, 20);
		obj.setModel(buff);
		for (count = 0; count < 20 && buff[count] != 0; ++count) {}
		fileDeposition += count + 1;

		in >> buff;				//in >> number;
		number=atoi(buff);		
		obj.setCapacity(number);
		for (count = 0; count < 20 && buff[count] != 0; ++count) {}
		fileDeposition += count + 1;

		in >> buff;				//in >> number;
		number = atoi(buff);
		obj.setSize(number);
		for (count = 0; count < 20 && buff[count] != 0; ++count) {}
		fileDeposition += count + 1;

		in >> buff;				//in >> number;
		number = atoi(buff);
		obj.setExtra(number);
		for (count = 0; count < 20 && buff[count] != 0; ++count) {}
		fileDeposition += count + 1 ;//+1 // if <<' ';

		in.close();
	}
}
bool DataManagerFile::SaveSize(const unsigned int& type, unsigned int*& ptr) const
{
	ofstream out("sizestorage.txt");
	if (out.is_open())
	{
		out << type << ' ';
		for (unsigned int i = 0U; i < type; ++i)
		{
			out << ptr[i] << ' ';
		}
		out << endl;
		out.close();
	}
	else
	{
		return false;
	}

	ofstream outt("storage.txt");
	return true;
}
bool DataManagerFile::LoadSize(unsigned int& type, unsigned int* & ptr)
{
	ifstream in("sizestorage.txt");
	if (in.is_open())
	{
		in >> type;

		ptr = new unsigned int[type];
		for (unsigned int i = 0U; i < type; ++i)
		{
			in >> ptr[i];
		}
		in.close();
	}
	else
	{
		return false;
	}

	return true;
}