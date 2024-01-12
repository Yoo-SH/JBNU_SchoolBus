#pragma once

#include <iostream>
#include <list>
#include <string>
#include "Time.h"
#include "DrivingTime.h"


using namespace std;

class BusStop {
public: //private으로 바꾸고 friend 선언하기
    string name; // 정류장 이름
    Time stop_time;   // 버스가 해당 정류장에 도착하는 시간표시

public:
    BusStop(const std::string& BusStop_name, Time BusStop_time);
};

class Bus {
protected:
    list<BusStop> route; // 버스 정류장 객체에 대한 인접 리스트, has-a 관계
    Time starting_time; //출발시간 의미
    Time end_time; //종점 도착시간
    

public:
    Bus(int Bus_hour, int Bus_minute, int Bus_second) : starting_time(Bus_hour, Bus_minute, Bus_second), end_time(Bus_hour, Bus_minute + 20, Bus_second) {};
    virtual void list_init(Time ref) =0; //순수가상함수
    virtual void print_current_location() = 0; //버스의 현재 정류장 위치를 나타냄
    string get_current_loacation();
    void addBusStop(const std::string& BusStop_name, Time BusStop_time); //정류장을 리스트 추가
    bool isDriving(); //버스가 운행 중인지를 나타내는 판단하는 함수
    Time calcul_time(const std::string& start_stop_name, const std::string& target_stop_name); //출발 정류장에서 도착 정류장 까지의 시간 반환
    void print_info(); //경로와 시간을 나타냄
    bool is_having_BusStop(string);
    
   
};

class CircularBus : public Bus {
public:
    CircularBus(int CircularBus_hour, int CircularBus_minute, int CircularBus_second); //CircularBus의 생성자
    ~CircularBus(); //CircularBus 객체가 가지는 리스트를 동적해제 시킴
    virtual void list_init(Time start_time); //CircularBus의 초기화함수
    virtual void print_current_location();
    
};

class RoundTripBus : public Bus {
public:
    RoundTripBus(int RoundTripBus_hour, int RoundTripBus_minute, int RoundTripBus_second);
    ~RoundTripBus(); //RoundTripBus가 객체가 가지는 리스트를 동적해제 시킴
    virtual void list_init(Time start_time);
    virtual void print_current_location();
};

