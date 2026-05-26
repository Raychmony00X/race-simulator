#pragma once
#include "AirTransport.h"
#include "Export.h"

class  FlyingCarpet: public AirTransport
{
public:
	FlyingCarpet();
	int getSpeed() const override;
};