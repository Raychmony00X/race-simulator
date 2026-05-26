#include "pch.h"
#include "Eagle.h"

Eagle::Eagle():AirTransport(8){}
int Eagle::getSpeed() const { return 8; }