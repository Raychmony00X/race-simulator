#pragma once
#include "Camel.h"
#include "Export.h"

class  FastCamel: public Camel
{
public:
	FastCamel();
	int getSpeed() const override;
	int getMovementTime() const override;
	int getRestTime() const override;
};