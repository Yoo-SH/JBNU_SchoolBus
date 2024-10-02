#pragma once

class Time {
private:
    int hour;       //시
    int minute;     //분
    int second;     //초

public:
    Time(int Time_hour = 0, int Time_minute = 0, int Time_second = 0); //TIME클래스 생성자

    void time_ordering(); //시간을 재정렬 하는 함수
    int get_hour();       //시 값을 가져오는 함수
    int get_minute();     //분 값을 가져오는 함수
    int get_second();     //초 값을 가져오는 함수

    Time operator +(const Time& ref); //타임 오퍼레이터 +연산자 
    Time operator -(const Time& ref); //타임 오퍼레이터 -연산자
    Time& operator =(const Time& ref); //타임 오퍼레이터 =연산자
    Time& operator +=(const Time& ref);//타임 오퍼레이터 +=연산자
    Time& operator -=(const Time& ref);//타임 오퍼레이터 -=연산자
    bool operator >(const Time& ref);//타임 오퍼레이터 >연산자
    bool operator <(const Time& ref);//타임 오퍼레이터 <연산자
    bool operator >=(const Time& ref);//타임 오퍼레이터 >=연산자
    bool operator <=(const Time& ref);//타임 오퍼레이터 <=연산자
    bool operator ==(const Time& ref);//타임 오퍼레이터 ==연산자
    bool operator > (const Time& ref) const;//타임 오퍼레이터 >연산자
    bool operator <(const Time& ref) const;//타임 오퍼레이터 <연산자
    bool operator ==(const Time& ref) const;//타임 오퍼레이터 ==연산자
    bool operator !=(const Time& ref) const;//타임 오퍼레이터 ==연산자

    friend std::ostream& operator<<(std::ostream& os, const Time& ref); //<<연산자

    Time& add_hour(int h);          //시 값을 추가하는 함수 
    Time& add_minute(int m);        //분 값을 추가하는 함수
    Time& add_second(int s);        //초 값을 추가하는 함수

    void print_time();//시간을 출력하는 함수
    void print_time() const;              
};


