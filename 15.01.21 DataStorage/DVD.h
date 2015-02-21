#pragma once
#include "Storage.h" 

class DVD : public Storage
{
	int recording_speed;

public:
	DVD();
	virtual~DVD();
	void setSpeedrec(int _recording_speed);
	int getSpeedrec()const;

	virtual void setExtra(int number) ;
	virtual int getExtra()const ;
};