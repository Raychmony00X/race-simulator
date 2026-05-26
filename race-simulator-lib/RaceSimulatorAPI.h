#pragma once

#ifdef RACESIMULATOR_EXPORTS
#define RACESIMULATOR_API __declspec(dllexport)
#else
#define RACESIMULATOR_API __declspec(dllimport)
#endif
