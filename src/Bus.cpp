#include "Bus.h"
#include "Person.h"



     //////////////////////////////////////////////BusStop클래스 정의///////////////////////////////////////////////////////    
    BusStop :: BusStop(const string& BusStop_name, Time BusStop_time) : name(BusStop_name)  //버스 정류장 객체 생성자
    {
        stop_time = BusStop_time; //대입 연산자
    }
    void Bus:: addBusStop(const string& BusStop_name, Time BusStop_time)  // 버스 정류장을 리스트에 추가
    {
        BusStop busStop(BusStop_name, BusStop_time); //has 관계, 리스트에 들어갈 정류장 객체.
        route.push_back(busStop);

    }

    //////////////////////////////////////////////Bus클래스 정의///////////////////////////////////////// ///////////////////

    
    bool Bus::isDriving()
    {

        if (starting_time > Person::current_time) //현재 시각이 출발 시간보다 빠르면 
        {
            return false;
        }
        else if (end_time < Person::current_time) //현재 시각이 종점 시간을 지났으면
        {
            return false;
        }
        else
        {
            return true;
        }

    }

    string Bus::get_current_loacation()
    {
        try
        {
            if (route.front().stop_time > Person::current_time || (route.back().stop_time < Person::current_time))//현재 시간이 루트의 종점 시간보다 크거나, 루트이 시작 시간보다 작다면
                throw "exception";
            else
            {
                for (list<BusStop>::iterator itr = route.begin(); itr != route.end(); itr++) //버스 리스트를 순환하며 현재시간을 기준으로 다음 정류장 나올 곳 캐치
                {

                    if ((*itr).stop_time > Person::current_time)
                    {
                        itr--;
                        return  (*itr).name;

                    }
                }

            }
        }
        catch (string)
        {
            if (starting_time > Person::current_time) //현재 시각이 출발 시간보다 이르면
            {
                cout << "Bus not yet start";
            }
            else if (end_time < Person::current_time) //현재 시각이 종점 시간을 지났으면
            {
                cout << "Bus already gone";
            }

        }

    }

    Time Bus::calcul_time(const string& start_stop_name, const string& target_stop_name) //출발 정류장에서 도착 정류장 까지의 시간 반환
    {

        Time total_distance_time;
        Time starting_time;
        Time tartget_time;


        for (BusStop& stop : route) {
            

            if (stop.name == start_stop_name && stop.stop_time != route.back().stop_time) {
                    
                starting_time = stop.stop_time;  //출발 지점의 시간을 찾아서 대입
              //  cout << stop.name << starting_time << endl;

            }

            if (stop.name == target_stop_name)
            {
                tartget_time = stop.stop_time;  //도착 지점의 시간을 찾아서 대입
                //cout << stop.name << tartget_time << endl;
            }

        }
        

        total_distance_time = tartget_time - starting_time;
      // cout << "총 시간" << total_distance_time << endl;
        return total_distance_time;

    }
    

   
     void Bus:: print_info() {
        for (const auto & entry : route) {
            cout << entry.name << " (time:) ";
            entry.stop_time.print_time();
        }
        cout << endl;
    }


     bool Bus::is_having_BusStop(string ref)
     {
         for (const auto& busStop : route)
         {
             if (busStop.name == ref)
                 return true;
         }
         return false;
     }
       
          
        

       /////////////////////////////////////////////////////CircularBus 정의/////////////////////////////////////////////////////////
       

       CircularBus::CircularBus(int CircularBus_hour, int CircularBus_minute, int CircularBus_second) : Bus(CircularBus_hour, CircularBus_minute, CircularBus_second)
       {
           list_init(starting_time); //생성자 생성시 초기화;
       }

       CircularBus :: ~CircularBus()
       {
           route.clear();
       }

       void CircularBus::print_current_location()
       {
           try
           {
               if (route.front().stop_time > Person::current_time || (route.back().stop_time < Person::current_time))//현재 시간이 루트의 종점 시간보다 크거나, 루트이 시작 시간보다 작다면
                   throw "exception";
               for (list<BusStop>::iterator itr = route.begin(); itr != route.end(); itr++) //버스 리스트를 순환하며 현재시간을 기준으로 다음 정류장 나올 곳 캐치
               {


                   if ((*itr).stop_time > Person::current_time)
                   {
                       itr--;
                       cout << (*itr).name;

                       break;
                   }
               }
           }
           catch (string)
           {
               if (starting_time > Person::current_time) //현재 시각이 출발 시간보다 이르면
               {
                   cout << "순환 버스가 출발까지 " << (starting_time - Person::current_time) << "남았습니다." << endl;
               }
               else if (end_time < Person::current_time) //현재 시각이 종점 시간을 지났으면
               {
                   cout << "순환 버스가 운행이 끝났습니다." << endl;
               }

           }

       }

       

     void CircularBus:: list_init(Time start_time)
     {

        addBusStop("생활관", start_time);
        addBusStop("2학생회관", start_time.add_minute(DrivingTime :: from생활관to2학생회관));
        addBusStop("진수당", start_time.add_minute(DrivingTime ::from2학생회관to진수당));
        addBusStop("생활대", start_time.add_minute(DrivingTime ::from진수당to생활대));
        addBusStop("상대2호관", start_time.add_minute(DrivingTime :: from생활대to상대2호관));
        addBusStop("학습도서관", start_time.add_minute(DrivingTime :: from상대2호관to학습도서관));
        addBusStop("농생대본관", start_time.add_minute(DrivingTime ::from학습도서관to농생대본관));
        addBusStop("예체능관", start_time.add_minute(DrivingTime::from농생대본관to예체능관));
        addBusStop("생활관", start_time.add_minute(DrivingTime :: from예체능관to생활관)); //종착점은 생활관
        
    }


     
     /////////////////////////////////////////////////////////////  RoundTripBus 정의 ///////////////////////////////////////////////////////////
     
   

     RoundTripBus::RoundTripBus(int RoundTripBus_hour, int RoundTripBus_minute, int RoundTripBus_second) : Bus(RoundTripBus_hour, RoundTripBus_minute, RoundTripBus_second)
     {
         list_init(starting_time); //생성자 생성과 동시에 초기화
     }

     RoundTripBus :: ~RoundTripBus()
     {
         route.clear();
     }

     void RoundTripBus::print_current_location()
     {
         try
         {
             if (route.front().stop_time > Person::current_time || (route.back().stop_time < Person::current_time))//현재 시간이 루트의 종점 시간보다 크거나, 루트이 시작 시간보다 작다면
                 throw "exception";
             for (list<BusStop>::iterator itr = route.begin(); itr != route.end(); itr++) //버스 리스트를 순환하며 현재시간을 기준으로 다음 정류장 나올 곳 캐치
             {


                 if ((*itr).stop_time > Person::current_time)
                 {
                     itr--;
                     cout << (*itr).name;

                     break;
                 }
             }
         }
         catch (string)
         {
             if (starting_time > Person::current_time) //현재 시각이 출발 시간보다 이르면
             {
                 cout << "왕복 버스가 출발까지 " << (starting_time - Person::current_time) << "남았습니다." << endl;
             }
             else if (end_time < Person::current_time) //현재 시각이 종점 시간을 지났으면
             {
                 cout << "왕복 버스가 운행이 끝났습니다." << endl;
             }

         }

     }

    

    
    void RoundTripBus::list_init(Time start_time)
    {
        addBusStop("생활관", start_time);
        addBusStop("2학생회관", start_time.add_minute(DrivingTime :: from생활관to2학생회관));
        addBusStop("대학본부", start_time.add_minute(DrivingTime ::from2학생회관to대학본부));
        addBusStop("정보전산원", start_time.add_minute(DrivingTime ::from대학본부to정보전산원));
        addBusStop("치의학전문대학원", start_time.add_minute(DrivingTime :: from정보전산원to치의학전문대학원));
        addBusStop("간호대학", start_time.add_minute(DrivingTime :: from치의학전문대학원to간호대학));
        addBusStop("정보전산원", start_time.add_minute(DrivingTime :: from간호대학to정보전산원));
        addBusStop("진수당", start_time.add_minute(DrivingTime :: from정보전산원to진수당));
        addBusStop("예체능관", start_time.add_minute(DrivingTime :: from진수당to예체능관));
        addBusStop("생활관", start_time.add_minute(DrivingTime::from예체능관to생활관)); //순환기점 은 생활관
    }

