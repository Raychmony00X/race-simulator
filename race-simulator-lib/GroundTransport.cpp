#include "pch.h"
#include "GroundTransport.h"

GroundTransport::GroundTransport(int newSpeed, int newMovementTime, int newRestTime): speed_(newSpeed),
movementTime_(newMovementTime), restTime_(newRestTime){ }
int GroundTransport::getSpeed() const { return speed_; }
int GroundTransport::getMovementTime() const { return movementTime_; }
int GroundTransport::getRestTime() const { return restTime_; }