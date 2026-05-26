#pragma once
#include "Export.h"

class  AirTransport
{
public:
	AirTransport(int newSpeed);
	virtual int getSpeed() const;
	
protected:
	int speed_;
};