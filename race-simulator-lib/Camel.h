#pragma once
#include "GroundTransport.h"
#include "Export.h"

class  Camel: public GroundTransport
{
public:
	Camel(int newSpeed = 10, int newMovementTime = 30, int newRestTime = 5);
	int getSpeed() const override;
	int getMovementTime() const override;
	int getRestTime() const override;
};