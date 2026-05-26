#pragma once


#ifdef RaceSimulatorDynamicLib_EXPORTS
#define RACE_API __declspec(dllexport)
#else
#define RACE_API __declspec(dllimport)
#endif