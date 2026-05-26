#pragma once
#include "GroundTransport.h"
#include "Export.h" 

class  Boots: public GroundTransport
{
public:
	Boots();
	int getSpeed() const override;
	int getMovementTime() const override;
	int getRestTime() const override;
};