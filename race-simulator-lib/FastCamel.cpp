#include "pch.h"
#include "FastCamel.h"

FastCamel::FastCamel():Camel(40, 10, 5){}
int FastCamel::getSpeed() const { return 40; }
int FastCamel::getMovementTime() const { return 10; }
int FastCamel::getRestTime() const { return 5; }