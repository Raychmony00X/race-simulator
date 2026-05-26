#pragma once
#include "Export.h"

class GroundTransport
{
public:
	GroundTransport(int newSpeed, int newMovementTime, int newRestTime);
	virtual int getSpeed() const;
	virtual int getMovementTime() const;
	virtual int getRestTime() const;

protected:
	int speed_, movementTime_, restTime_;
};