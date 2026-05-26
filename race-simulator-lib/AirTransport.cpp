#include "pch.h"
#include "AirTransport.h"

AirTransport::AirTransport(int newSpeed ): speed_(newSpeed){}
int AirTransport::getSpeed() const { return speed_; }
