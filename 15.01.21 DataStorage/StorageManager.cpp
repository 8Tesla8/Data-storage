#include "StorageManager.h"

StorageManager::StorageManager() :
ptr(nullptr), 
methodInOut(new InOutConsole), methodSL(new DataManagerFile),
TypeStorage(3U),
sizeStorage(new unsigned int[TypeStorage]),		// массив количества устройств 0 - DVD size, 1 - HardDisk size, 2 - USB size
oldSizeStorage(new unsigned int[TypeStorage]),	// old size massif, need if choice = 2 || choice = 4 (add, delete)
sizeAll(0U), oldSizeAll(0U),
find(0U), findIndex(nullptr)
{
	for (unsigned int i = 0U; i < TypeStorage; ++i)
		oldSizeStorage[i] = sizeStorage[i] = 0U;
}
StorageManager::~StorageManager()
{
	delete methodInOut;
	delete methodSL;

	delete[]sizeStorage;
	delete[]oldSizeStorage;

	if (sizeAll)
	{
		for (unsigned int i = 0U; i < sizeAll; ++i)
			delete ptr[i];

		delete[]ptr;
	}

	if (findIndex != nullptr)	delete[]findIndex;
}
void StorageManager::Menu()
{	
	int choice = 0; 

	while (true)
	{	

		oldSizeAll = 0;
		for (unsigned int i = 0; i < TypeStorage; ++i) // old size massif, need if choice = 2 || choice = 3 (add, delete) 
		{
			oldSizeStorage[i] = sizeStorage[i];
			oldSizeAll += oldSizeStorage[i];
		}			

		methodInOut->ChoiceMenu(TypeStorage, sizeStorage, choice);

		sizeAll = 0;
		for (unsigned int i = 0; i < TypeStorage; ++i)	//0 - DVD size, 1 - HardDisk size, 2 - USB size
			sizeAll += sizeStorage[i];

		if (!choice)		//0 - exit
		{
			break;
		}
		else if (choice==1)	// creation 
		{
			Create();
		}
		else if (choice == 2) // add	
		{
			Add();
		}
		else if (choice == 3) // delete			
		{			
			Serch();
			Delete();
		}
		else if (choice == 4) // edit	
		{
			Serch();
			Edit();
		}
		else if (choice == 5) // print
		{
			Print();
		}
		else if (choice == 6) //serch	
		{
			Serch();	
		}
		else if (choice == 7) // Sorting		//как убрать множество выборов при этом действия остаются те жe
		{
			Sorting();
		}
		else if (choice == 8) // Save			//как уведомить что файл не открылся????? в метод
		{
			Save();
		}
		else if (choice == 9) // Load
		{
			Load();
		}
	} 
}
void StorageManager::Create()
{
	if (sizeAll)
	{
		ptr = new Storage*[sizeAll];

		for (unsigned int i = 0U, count = 0U; i < TypeStorage; ++i)
		{
			if (sizeStorage[i])
			{
				for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
				{
					if (!i)				ptr[count] = new DVD;
					else if (i == 1)	ptr[count] = new HardDisk;
					else if (i == 2)	ptr[count] = new USB;

					methodInOut->InputData(*ptr[count++]);
				}
			}
		}
	}
}
void StorageManager::Add()
{
	if (sizeAll)
	{	
		Storage **tempPtr = new Storage*[sizeAll];

		for (unsigned int i = 0U, newCount = 0U, oldCount = 0U; i < TypeStorage; ++i)
		{
			if (sizeStorage[i])
			{
				if (oldSizeStorage[i] != sizeStorage[i])
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
					{
						if (j < oldSizeStorage[i])		// recording old object
						{
							tempPtr[newCount++] = ptr[oldCount++];
						}
						else							//add new object
						{
							if (!i)				tempPtr[newCount] = new DVD;
							else if (i == 1)	tempPtr[newCount] = new HardDisk;
							else if (i == 2)	tempPtr[newCount] = new USB;

							methodInOut->InputData(*tempPtr[newCount++]);
						}
					}
				}
				else	// if not change in size storage DVD, Hard disk, USB
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
						tempPtr[newCount++] = ptr[oldCount++];
				}
			}
		}
		Storage **delPtr = ptr;
		ptr = tempPtr;
		delete[]delPtr;
	}
}
void StorageManager::Delete()
{
	if (find && sizeAll)
	{
		int which = 0;
		methodInOut->WhichMenu(find, which, false);	// false for delete

		if (which != -1)
		{
			Storage **tempPtr = new Storage*[sizeAll - 1U];
			if (!(sizeAll - 1U))
			{
				delete[]tempPtr;
				tempPtr = nullptr;
			}

			for (unsigned int i = 0U, newCount = 0U, oldCount = 0U; i < TypeStorage; ++i)
			{
				if (sizeStorage[i])
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
					{
						if (findIndex[which] == oldCount)
						{
							++oldCount;
							--sizeAll;
							--sizeStorage[i];
						}
						else
						{
							tempPtr[newCount++] = ptr[oldCount++];
						}					
					}
				}
			}
			delete ptr[findIndex[which]];

			Storage **delPtr = ptr;
			ptr = tempPtr;

			delete[]delPtr;
		}
	}
}
void StorageManager::Serch()
{
	if (sizeAll)
	{
		find = 0;
		int criteria = 1;
		char serchBuff[20] = {};
		methodInOut->SerchMenu(criteria, serchBuff);

		if (criteria)
		{
			if (findIndex == nullptr)
			{
				findIndex = new int[sizeAll];
			}
			else if (findIndex != nullptr)	//++++++++ 
			{
				delete[]findIndex;
				findIndex = new int[sizeAll];
			}

			for (unsigned int i = 0U; i < sizeAll; ++i)
				findIndex[i] = -1;

			unsigned int type = 0;
			for (unsigned int i = 0U, countFind = 0U, count = 0U; i < TypeStorage; ++i)
			{
				if (sizeStorage[i])
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
					{
						if (criteria == 1 && strcmp(ptr[count]->getName(), serchBuff) == 0)
						{
							findIndex[countFind++] = count;
							++find;
							methodInOut->OutputData(*ptr[count], i);
						}
						else if (criteria == 2 && strcmp(ptr[count]->getModel(), serchBuff) == 0)
						{
							findIndex[countFind++] = count;
							++find;
							methodInOut->OutputData(*ptr[count], i);
						}
						++count;
					}
				}
			}
			/*
			for (unsigned int i = 0U, count = 0U; i < sizeAll; ++i)
			{
			if (criteria == 1 && strcmp(ptr[i]->getName(), serchBuff) == 0)
			{
			findIndex[count++] = i;
			++find;
			}
			else if (criteria == 2 && strcmp(ptr[i]->getModel(), serchBuff) == 0)
			{
			findIndex[count++] = i;
			++find;
			}
			}
			*/
			/*
			if (find)	// print tempFind
			{
			for (unsigned int i = 0U; i <find; ++i)
			methodInOut->OutputData(*ptr[findIndex[i]],  );//
			}
			*/

			if (!find)		// nothing found
			{
				criteria = 0;
				methodInOut->SerchMenu(criteria, serchBuff);
			}

			/*
			// algoritm based on pointer
			if (serchPtr == nullptr)
			{
			serchPtr = new Storage*[sizeAll];
			}
			else if (serchPtr != nullptr)
			{
			delete[]serchPtr;
			serchPtr = new Storage*[sizeAll];
			}

			for (unsigned int i = 0U; i < sizeAll; ++i)
			serchPtr[i] = nullptr;

			find = 0;
			for (unsigned int i = 0U, count = 0U; i < sizeAll; ++i)
			{
			if (serchCriteria == 1 && strcmp(ptr[i]->getName(), serchBuff) == 0)
			{
			serchPtr[count++] = ptr[i];
			++find;
			}
			else if (serchCriteria == 2 && strcmp(ptr[i]->getModel(), serchBuff) == 0)
			{
			serchPtr[count++] = ptr[i];
			++find;
			}
			}

			if (find)	// print tempFind
			{
			for (unsigned int i = 0U; i <find; ++i)
			methodInOut->OutputData(*serchPtr[i]);
			}
			else		// nothing found
			{
			serchCriteria = 0;
			methodInOut->SerchMenu(serchCriteria, serchBuff);
			}
			*/
		}	
	}
}
void StorageManager::Print()const
{
	if (sizeAll)
	{
		for (unsigned int i = 0U, count = 0U; i < TypeStorage; ++i)
		{
			if (sizeStorage[i])
			{
				for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
				{
					methodInOut->OutputData(*ptr[count++], i);
				}
			}
		}

		//for (unsigned int i = 0U; i < sizeAll; ++i)	methodInOut->OutputData(*ptr[i], );
	}
}
void StorageManager::Edit()
{
	if (find && sizeAll)
	{
		int which = 0;
		methodInOut->WhichMenu(find, which, true); // true for edit

		if (which != -1)
		{
			methodInOut->InputData(*ptr[findIndex[which]]);
		}
	}
}
void StorageManager::Sorting()		
{
	if (sizeAll)
	{
		int criteria = 0;
		methodInOut->SortingMenu(criteria);

		if (criteria)
		{
			Storage *temp = nullptr;

			for (unsigned int i = 0U, count = 0U; i < TypeStorage; ++i)
			{
				if (sizeStorage[i])
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
					{
						for (unsigned int k = j + 1U; k < sizeStorage[i]; ++k)
						{
							//как убрать множество выборов при этом действия остаются те же++++++++
							if (criteria == 1 && strcmp(ptr[j]->getName(), ptr[k]->getName()) > 0)
							{
								temp = ptr[j];
								ptr[j] = ptr[k];
								ptr[k] = temp;
							}
							else if (criteria == 2 && strcmp(ptr[j]->getModel(), ptr[k]->getModel()) > 0)
							{
								temp = ptr[j];
								ptr[j] = ptr[k];
								ptr[k] = temp;
							}
							else if (criteria == 3 && ptr[j]->getCapacity() > ptr[k]->getCapacity())
							{
								temp = ptr[j];
								ptr[j] = ptr[k];
								ptr[k] = temp;
							}
							else if (criteria == 4 && ptr[j]->getSize() > ptr[k]->getSize())
							{
								temp = ptr[j];
								ptr[j] = ptr[k];
								ptr[k] = temp;
							}
							else if (criteria == 5 && ptr[j]->getExtra() > ptr[k]->getExtra())
							{
								temp = ptr[j];
								ptr[j] = ptr[k];
								ptr[k] = temp;
							}
						}
					}
				}
			}
		}
	}
}
void StorageManager::Save()
{
	//methodSaveLoad->SaveStorage(&this);	//not work 

	bool open = methodSL->SaveSize(TypeStorage, sizeStorage);
	if (open)
	{
		for (unsigned int i = 0U; i < sizeAll; ++i)
		{
			open = methodSL->SaveObj(*ptr[i]);
			if (!open)
			{
				methodInOut->InfoSL();
				return;
			}
		}
			
	}
	else
	{
		methodInOut->InfoSL();
	}
}
void StorageManager::Load()
{
	unsigned int type = 0U;
	unsigned int* pt = nullptr;

	bool open = methodSL->LoadSize(type, pt);
	if (open)
	{
		unsigned int size = 0U;
		for (unsigned int i = 0; i < type; ++i)
			size += pt[i];

		if (size)
		{
			if (sizeStorage != nullptr)
				delete[]sizeStorage;

			TypeStorage = type;
			sizeStorage = pt;
			sizeAll = size;

			// creation 
			if (ptr != nullptr)
			{
				for (unsigned int i = 0U; i < sizeAll; ++i)
					delete ptr[i];

				delete[]ptr;
			}

			ptr = new Storage*[sizeAll];
			for (unsigned int i = 0U, count = 0U, fileDeposition = 0U; i < TypeStorage; ++i)
			{
				if (sizeStorage[i])
				{
					for (unsigned int j = 0U; j < sizeStorage[i]; ++j)
					{
						if (!i)				ptr[count] = new DVD;
						else if (i == 1)	ptr[count] = new HardDisk;
						else if (i == 2)	ptr[count] = new USB;
						//1 variant
						//methodSL->LoadObj(*ptr[count], fileDeposition);	//fileDeposition = 0U - смещение в файле
						count++;
					}
				}
			}
			// 2 variant
			open = methodSL->Load2(ptr, sizeAll);
			if (!open)
			{
				methodInOut->InfoSL();

				for (unsigned int i = 0U; i < sizeAll; ++i)
					delete ptr[i];

				delete[]ptr;
				ptr = nullptr;
			}
		}
		else
		{
			delete[]pt;
		}
	}
	else
	{
		methodInOut->InfoSL();
	}
}