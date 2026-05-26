#pragma once
#include "AirTransport.h"
#include "Export.h"

class  Eagle: public AirTransport
{
public:
	Eagle();
	int getSpeed() const override;
};