#include<iostream>
#include"Time.h"
using namespace std;



	Time :: Time(int Time_hour , int Time_minute , int Time_second ) : hour(Time_hour), minute(Time_minute), second(Time_second)
	{
		time_ordering();
	}
	void Time:: time_ordering()
	{

		
		if (hour < 0 || minute < 0 || second < 0)
		{
			if (second < 0)
			{
				minute--;
				second += 60;
			}
			else if (minute < 0)  
			{
				hour--;
				minute += 60;
			}
			else //시 단위가 음수인 경우는 연산을 위해 시 단위만 음수로 표현함
			{
				minute = 0;
			}
			
		}
		if (second >= 60)
		{
			minute += second / 60;
			second = 0;
		}
		if (minute >= 60)
		{
			hour += minute / 60;
			minute = 0;
		}
		if (hour >= 24) //자정을 넘으면 00시로 표기
			hour -= 24;
		
	}
	int Time:: get_hour()
	{
		return hour;
	}
	int Time:: get_minute()
	{
		return minute;
	}
	int Time:: get_second()
	{
		return second;
	}
	Time Time :: operator +(const Time& ref)
	{
		Time t(hour + ref.hour, minute + ref.minute, second + ref.second);
		t.time_ordering();

		return t;
	}
	Time Time :: operator -(const Time& ref)
	{
		Time t(hour - ref.hour, minute - ref.minute, second - ref.second);
		t.time_ordering();

		return t;
	}
	Time& Time :: operator =(const Time& ref)
	{
		hour = ref.hour;
		minute = ref.minute;
		second = ref.second;
		time_ordering();

		return *this;
	}
	Time& Time :: operator +=(const Time& ref)
	{
		(this)->hour += ref.hour;
		(this)->minute += ref.minute;
		(this)->second += ref.second;
		return *this;
	}
	Time& Time :: operator -=(const Time& ref)
	{
		*this = *this - ref;
		return *this;
	}
	bool Time :: operator > (const Time& ref)  //초로 반환해서 시간을 비교하는 오퍼레이터 연산자
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second > temp_ref_second);
	}
	bool Time :: operator >=(const Time& ref)  //초로 반환해서 시간을 비교하는 오퍼레이터 연산자
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second >= temp_ref_second);
	}
	bool Time :: operator <= (const Time& ref)  //초로 반환해서 시간을 비교하는 오퍼레이터 연산자
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second <= temp_ref_second);
	}
	bool Time :: operator < (const Time& ref)
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second < temp_ref_second);
	}
	bool Time :: operator ==(const Time& ref)
	{
		return (hour == ref.hour && minute == ref.minute && second == ref.second);
	}
	bool Time :: operator > (const Time& ref) const //초로 반환해서 시간을 비교하는 오퍼레이터 연산자
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second > temp_ref_second);
	}
	bool Time :: operator < (const Time& ref) const
	{
		int temp_second = (hour * 60 * 60) + (minute * 60) + second;
		int temp_ref_second = (ref.hour * 60 * 60) + (ref.minute * 60) + ref.second;

		return (temp_second < temp_ref_second);
	}
	bool Time :: operator ==(const Time& ref) const
	{
		return (hour == ref.hour && minute == ref.minute && second == ref.second);
	}
	bool Time :: operator !=(const Time& ref) const
	{
		return (hour != ref.hour || minute != ref.minute || second != ref.second);
	}
	std::ostream& operator<<(std::ostream& os, const Time& ref) {
		os << ref.hour << ":" << ref.minute << ":" << ref.second;
		return os;
	}
	
	Time& Time:: add_hour(int h)
	{
		hour += h;
		time_ordering();
		return*this;
	}
	Time& Time:: add_minute(int m)
	{
		minute += m;
		time_ordering();
		return*this;
	}
	Time& Time:: add_second(int s)
	{
		second += s;
		time_ordering();
		return*this;
	}
	void Time::print_time()
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}
	void Time:: print_time () const
	{
		cout << hour << ":" << minute << ":" << second << endl;
	}




