#pragma once

#include <iostream>
#include<string>
#include "Time.h"
#include "Bus.h"
#include "WalkingMap.h"

class Person {
private:
	string starting_location; //현재 위치
	string target_location; //목표 위치
	WalkingMap starting_location_map; //사람이 출발 지점에서 다른 건물사이까지 걸어가는 시간을 정리한 map (map 구조 has-a)
	WalkingMap target_location_map; //사람이 타겟 지점에서 다른 건물사이까지 걸어가는 시간을 정리한 map (map 구조 has-a)


public:
	Person() : starting_location(""), target_location(""), starting_location_map(""), target_location_map(""){};
	Person(string Person_start, string Person_target) : starting_location(Person_start), target_location(Person_target), starting_location_map(Person_start), target_location_map(Person_target)  //생성자를 초기화하면서 도착지점과 출발지점을 입력합 + walking map이 시작 지점에 따라 map을 초기화 함.
	{
	
	}
	static Time current_time; //현재시각
	string findStartBusStop(); //현재 위치에서 가장 거리가 가까운 버스 정류장 위치를 찾음 
	string findTargetBusStop();
	Time getStartWalkingTime(const string& target); //출발점에서 초기화된 map을 따라 도착지점을 키로 사용하여 거리 시간을 가져온다.
	Time getTargetWalkingTime(const string& start); //목적지점에서 초기화된 map을 따라 출발지점을 키로 사용하여 거리 시간을 가져오는 함수


};


