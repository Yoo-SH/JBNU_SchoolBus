#include <iostream>
#include<string>
#include "Time.h"
#include "Bus.h"
#include "Person.h"


 Time Person::current_time(0, 0, 0);

 Time Person:: getStartWalkingTime(const string& target) //시작값에서 초기화된 map을 따라 도착지점을 키로 사용하여 거리 시간을 가져온다.
{
	Time t(0, starting_location_map.schoolMap.find(target)->second, 0);
	return t;
}

 Time Person::getTargetWalkingTime(const string& start)
 {
	 Time t(0, target_location_map.schoolMap.find(start)->second,0);
	 return t;
 }

 string Person::findStartBusStop()
 {
	 int min = starting_location_map.schoolMap.begin()->second;
	 string stopName; 

	 for (const auto& stop : starting_location_map.schoolMap) {
		 if (stop.second < min) {
			 stopName = stop.first;
			 min = stop.second;
		 }
	 }

	 return stopName;
	 
 }

 string Person::findTargetBusStop()
 {
	 int min = target_location_map.schoolMap.begin()->second;
	 string stopName;

	 for (const auto& stop : target_location_map.schoolMap) {
		 if (stop.second < min) {
			 stopName = stop.first;
			 min = stop.second;
		 }
	 }

	 return stopName;

 }
