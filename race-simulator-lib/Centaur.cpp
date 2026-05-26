#include "pch.h"
#include "Centaur.h"

Centaur::Centaur():GroundTransport(15, 8, 2){}
int Centaur::getSpeed() const { return 15; }
int Centaur::getMovementTime() const { return 8; }
int Centaur::getRestTime() const { return 2; }