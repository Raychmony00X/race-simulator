#include "pch.h"
#include "Camel.h"

Camel::Camel(int newSpeed, int newMovementTime, int newRestTime): GroundTransport(newSpeed,
	newMovementTime, newRestTime){ }
int Camel::getSpeed() const { return 10; }
int Camel::getMovementTime() const { return 30; }
int Camel::getRestTime() const { return 5; }