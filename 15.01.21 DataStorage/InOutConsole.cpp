#pragma once
#include "InOutConsole.h"

void InOutConsole::ChoiceMenu(unsigned int& typeStorage, unsigned int *massif, int &choice)
{
	unsigned int size = 0;
	for (unsigned int i = 0; i < typeStorage; ++i)	//0 - DVD size, 1 - HardDisk size, 2 - USB size
		size += massif[i];

	while (true)
	{		
		cout << '\n'
			<< "1 - Creation storage\n"
			<< "2 - Add new storage\n"
			<< "3 - Delete storage\n"
			<< "4 - Edit storage\n"	
			<< "5 - Print\n"
			<< "6 - Search\n"
			<< "7 - Sorting\n"		
			<< "8 - Save\n"
			<< "9 - Load\n"
			<< "0 - Exit\n"
			<< "Enter number: ";
		cin >> choice; 
		if (!choice)
		{
			system("cls");
			break;
		}
		else if (choice == 1 || choice == 2)
		{
			system("cls");
			if (choice == 1 ? !size : size)	
			{
				int addCount = 0;

				for (unsigned int i = 0U; i < typeStorage; ++i)
				{
					if (!i)			 choice == 1 ? cout << "Enter count DVD: ":			cout << "Enter add count DVD: ";
					else if (i == 1) choice == 1 ? cout << "Enter count Hard disk: ":   cout << "Enter add count Hard disk: ";
					else if (i == 2) choice == 1 ? cout << "Enter count USB: ":			cout << "Enter add count USB: ";

					while (true)
					{
						cin >> addCount;
						if (addCount < 0)		 cout << "Invalid count. Try again: ";
						else if (addCount >= 0)  break;
					}
					choice == 1 ? massif[i] = addCount: massif[i] += addCount;
				}
				break;
			}
			else
			{
				choice == 1 ? cout << "You already have a list of storages.": cout << "You don't have a list of storages. You must create it.";
			}
		}
		else if (choice == 9 ) // load
		{
			system("cls");
			break;
		}
		else if (choice > 9 || choice < 0) 
		{
			system("cls");
			cout << "You enter invalid number, try againe.";
		}
		else 
		{
			system("cls");
			if (size)
			{
				break;
			}
			else
			{
				cout << "You don't have a list of storages. You must create it.";
			}
		}
	} 
}	
void InOutConsole::InfoSL()const
{
	cout << "File doesn't open.";
}
void InOutConsole::SerchMenu(int& choice, char * buff)
{
	if (choice)	
	{
		do{
			cout
				<< "\nSelect search criteria:\n"
				<< "1 - Name\n"
				<< "2 - Model\n"
				<< "0 - Cansel\n"
				<< "Enter number: ";
			cin >> choice;

			if		(choice == 1)	cout << "Enter the Name you wanna find: ";
			else if (choice == 2)	cout << "Enter the Model you wanna find: ";
			else
			{
				system("cls");
				cout << "You enter invalid number, try againe.";
			}

		} while (choice!=0 && choice != 1 && choice != 2);
		
		if (choice)
		{
			cin.ignore();
			cin.getline(buff, 20);
		}
		system("cls");
	}
	else if (!choice)	// if nothing found
	{
		system("cls");
		cout << "No results";
	}	
}
void InOutConsole::SortingMenu(int& choice)
{
	while (true)
	{
		cout << "\nSelect sorting criteria:\n"
			<< "1 - Name\n"
			<< "2 - Model\n"
			<< "3 - Capacity\n"
			<< "4 - Size\n"
			<< "5 - Recording speed for DVD, speed USB or \n    rotational speed for Hard disk\n"
			<< "0 - Cansel\n"
			<< "Enter number: ";
		cin >> choice;

		if (choice < 0 || choice > 5)
		{
			system("cls");
			cout << "\nYou enter invalid number, try againe.";
		}
		else break;
	}
	system("cls");
}
void InOutConsole::WhichMenu(unsigned int& find, int& which, bool or)
{
	while (true)
	{
		if (find == 1)
		{	
			cout << "\n1 - " << (or ? "edit." : "delete.");
			cout << "\n0 - cancel.";
		}
		else if (find > 1)
		{
			cout << "\nSelect what you wanna " << (or ? "edit." : "delete.");
			cout << "\n1, 2 or another number."
				<< "\n0 - cancel.";
		}

		cout << "\nEnter the number: ";
		cin >> which;

		if (which >= 0 && find >= which) break;
		else cout << "Your enter invalid number.\n";
	}
	system("cls");
	which -= 1;
}
void InOutConsole::InputData(Storage& obj)
{
	int number=0;
	char buff[20] = {};

	cout << "\nEnter data ";

	if (typeid(obj) == typeid(DVD))
		cout << "DVD:\n";
	else if (typeid(obj) == typeid(USB))
		cout << "USB:\n";
	else if (typeid(obj) == typeid(HardDisk))
		cout << "Hard Disk:\n";

	cin.ignore();

	cout << "Name: ";	
	cin.getline(buff, 20);
	obj.setName(buff);	
	
	cout << "Model: ";
	cin.getline(buff, 20);
	obj.setModel(buff);

	cout << "Capacity: ";
	cin >> number;
	obj.setCapacity(number);

	cout << "Size: ";
	cin >> number;
	obj.setSize(number);

	//Storage*p = &obj; // for RTTI
	if (typeid(obj) == typeid(DVD))
	{
		cout << "Recording speed: ";
		// RTTI not work
		/*
		cout << "Recording speed: ";
		cin >> number;
		cin >> obj.recording_speed;
		*/
	}
	else if (typeid(obj) == typeid(USB))
	{
		cout << "Speed USB: ";
		// RTTI not work
		/*
		dynamic_cast<USB>;
		cout << "Speed USB: ";
		cin >> number;
		obj.setSpeedUsb(number);
		*/
	}
	else if (typeid(obj) == typeid(HardDisk))
	{
		cout << "Rotational speed: ";
		// RTTI not work
		/*
		cout << "Rotationalspeed: ";
		cin >> number;
		cin >> obj.rotational_speed;
		*/
	}
	cin >> number;
	obj.setExtra(number);
}
void InOutConsole::OutputData(Storage& obj, unsigned int& num)const
{
	cout << "\nData ";

	if (!num )
		cout << "DVD:\n";
	else if (num==1)
		cout << "USB:\n";
	else if (num == 2)
		cout << "HardDisk:\n";
	/*
	if (typeid(obj) == typeid(DVD))
	cout << "DVD:\n";
	else if (typeid(obj) == typeid(USB))
	cout << "USB:\n";
	else if (typeid(obj) == typeid(HardDisk))
	cout << "HardDisk:\n";
	*/

	cout << "Name: " << obj.getName() << endl;
	cout << "Model: " << obj.getModel() << endl;
	cout << "Capacity: " << obj.getCapacity() << endl;
	cout << "Size: " << obj.getSize() << endl;

	if (!num)
		cout << "Recording speed: ";
	else if (num == 1)
		cout << "Speed USB: ";
	else if (num == 2)
		cout << "Rotational speed: ";
	/*
	if (typeid(obj) == typeid(DVD))
	{
	cout << "Recording speed: ";
	//RTTI		cout << "Recording speed: " << recording_speed << endl;
	}
	else if (typeid(obj) == typeid(USB))
	{
	cout << "Speed USB: ";
	//RTTI		cout << "Speed USB: " << obj.getSpeedUSB() << endl;
	}
	else if (typeid(obj) == typeid(HardDisk))
	{
	cout << "Rotational speed: ";
	//RTTI		cout << "Rotational speed: " << rotational_speed << endl;
	}
	*/

	cout << obj.getExtra() <<endl;
}