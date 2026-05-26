#include "pch.h"
#include "Functions.h"


std::variant<int, float> countFastCamelNextRestTime(int& distance)
{
	FastCamel fastCamel;
	int speed = fastCamel.getSpeed();
	int time = distance / speed;
	
	int count;
	if (time > fastCamel.getMovementTime()) { count = time / fastCamel.getMovementTime(); }
	else { count = fastCamel.getMovementTime() / time; }
	
	float secondRestTime, nextRestTime;
	if (count == 2) { return secondRestTime = 6.5f; }
	else if (count > 2) {return nextRestTime = 8;}
	return 0;
}

int countCamelResultTime(int& distance)
{
	Camel camel;
	int speed = camel.getSpeed();
	int time = distance / speed;
	
	if (time > camel.getMovementTime())
	{
		int count = time / camel.getMovementTime();
		return (count - 1) * 8 + 5;
	}
	else if (time == camel.getMovementTime()) { return time + camel.getRestTime(); }
	else { return time; }
}

std::variant<int, float> countFastCamelResultTime(int& distance)
{
	FastCamel fastCamel;
	int speed = fastCamel.getSpeed();
	int time = distance / speed;

	if (time > fastCamel.getMovementTime())
	{
		auto nextRestTime = countFastCamelNextRestTime(distance);
		int count = time / fastCamel.getMovementTime();
		return std::visit([count](auto&& value) -> int 
			{ return static_cast<int>((count - 1) * value + 5); }, nextRestTime);
	}
	else if (time == fastCamel.getMovementTime()) { return time + fastCamel.getRestTime(); }
	else { return time; }
}

int countCentaurResultTime(int& distance)
{
	Centaur centaur;
	int time = distance / centaur.getSpeed();
	if (time >= centaur.getMovementTime()) 
	{
		int count = time / centaur.getMovementTime();
		return count * centaur.getRestTime(); 
	}
	else { return time; }
}

int countBootsResultTime(int& distance)
{
	Boots boots;
	int speed = boots.getSpeed();
	int time = distance / speed;

	if (time > boots.getMovementTime())
	{
		int count = time / boots.getMovementTime();
		return (count - 1) * 5 + 10;
	}
	if (time == boots.getMovementTime()) { return time + boots.getRestTime(); }
	else { return time; }
}

int countFlyingCarpetResultTime(int& distance)
{
	FlyingCarpet flyingCarpet;
	int newDistance;
	if(distance < 1000)
	{
		return distance / flyingCarpet.getSpeed();
	}
	else if(distance >= 1000 && distance < 5000)
	{
		newDistance = distance * (1 - 0,03);
		return newDistance / flyingCarpet.getSpeed();
	
	}
	else if (distance >= 5000 && distance < 10000) 
	{
		newDistance = distance * (1 - 0,10);
		return newDistance / flyingCarpet.getSpeed();
	}
	else if(distance >= 10000)
	{
		newDistance = distance * (1 - 0,05);
		return newDistance / flyingCarpet.getSpeed();
	}
	else { return 0; }
}

int countEagleResultTime(int& distance)
{
	Eagle eagle;
	int newDistance = distance * (1 - 0,06);
	return newDistance / eagle.getSpeed();
}

int countBroomResultTime(int& distance)
{
	Broom broom;
	int index = distance / 1000;
	int newDistance = 1000 * (1 - (index / 100));
	return newDistance / broom.getSpeed();
}