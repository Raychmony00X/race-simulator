#include "pch.h"
#include "FlyingCarpet.h"

FlyingCarpet::FlyingCarpet():AirTransport(10){}
int FlyingCarpet::getSpeed() const { return 10; }