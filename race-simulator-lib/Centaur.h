#pragma once
#include "GroundTransport.h"
#include "Export.h"

class  Centaur: public GroundTransport
{
public:
	Centaur();
	int getSpeed() const override;
	int getMovementTime() const override;
	int getRestTime() const override;
};