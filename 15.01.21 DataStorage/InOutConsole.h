#pragma once
#include "InOut.h"

class InOutConsole : public InOut
{
protected:
	virtual ~InOutConsole()
	{
	}

	void ChoiceMenu(unsigned int& typeStorage, unsigned int *massif, int &choice);
	void SerchMenu(int& choice, char * buff);
	void WhichMenu(unsigned int& find, int& which, bool or);
	void SortingMenu(int& choice);
	void InputData(Storage& obj);
	void OutputData(Storage& obj, unsigned int& count)const;
	virtual void InfoSL() const;
};