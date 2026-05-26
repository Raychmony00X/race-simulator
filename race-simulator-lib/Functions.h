#pragma once
#include <variant>
#include <iostream>

#include "MyLibrary.h"
#include "Export.h"

std::variant<int, float> countFastCamelNextRestTime(int& distance);

int countCamelResultTime(int& distance);

std::variant<int, float> countFastCamelResultTime(int& distance);

int  countCentaurResultTime(int& distance);

int countBootsResultTime(int& distance);

int  countFlyingCarpetResultTime(int& distance);

int countEagleResultTime(int& distance);

int countBroomResultTime(int& distance);