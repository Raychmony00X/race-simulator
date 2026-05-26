#pragma once
#include "AirTransport.h"
#include "Export.h"

class   Broom: public AirTransport
{
public:
	Broom();
	int getSpeed() const override;
};