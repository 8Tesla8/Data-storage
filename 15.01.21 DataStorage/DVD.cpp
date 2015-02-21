#include "DVD.h"

DVD::DVD() :
recording_speed(0)
{
}
DVD::~DVD()
{
}

void DVD::setSpeedrec(int _recording_speed)
{
	recording_speed = _recording_speed;
}
int DVD::getSpeedrec()const
{
	return recording_speed;
}
void  DVD::setExtra(int number)
{
	recording_speed = number;
}
int  DVD::getExtra()const
{
	return recording_speed;
}