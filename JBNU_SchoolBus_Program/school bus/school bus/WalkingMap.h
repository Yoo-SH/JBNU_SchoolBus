#pragma once

#include <map>
#include <string>
#include "iostream"
#include "WalkingTime.h"

using namespace std;

class WalkingMap {
public:
	map<string, int> schoolMap;
	WalkingMap(string starting_location);

};