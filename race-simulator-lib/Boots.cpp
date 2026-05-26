#include "pch.h"
#include "Boots.h"

Boots::Boots():GroundTransport(6, 60, 10){}
int Boots::getSpeed() const { return 6; }
int Boots::getMovementTime() const { return 60; }
int Boots::getRestTime() const { return 10; }