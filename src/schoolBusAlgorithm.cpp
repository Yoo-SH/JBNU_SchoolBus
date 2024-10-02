#include "Bus.h"
#include "Person.h"

int main()
{

    int h, m, s; //시, 분 , 초
    int circularbus_index = 0; //순환버스 인덱스
    int roundTripBuses_index = 0; //왕복버스 인덱스
    string start, target; //현위치, 목적지
    Time only_walk_time, bus_using_time; //걸어가는 시간과 버스타고 가는시간 비교를 위한 객체

    cout << "현재 시각을 입력하시오" << endl;;
    cout << "시: "; cin >> h;
    cout << "분: "; cin >> m;
    cout << "초: "; cin >> s;
    cout << "현위치를 입력하시오.:"; cin >> start;
    cout << "목적지를 입력하시오.:"; cin >> target;
    Time now(h, m, s);
    Person::current_time = now; //현재 시간 입력 ->전역변수
    Person me(start,target); // 현위치, 목적지 입력한 객체 생성

    
    CircularBus circulBuses[6] = {
       CircularBus(10, 30, 0),
       CircularBus(11, 00, 0),
       CircularBus(11, 30, 0),
       CircularBus(13, 00, 0),
       CircularBus(13, 30, 0),
       CircularBus(14, 00, 0)
    };

    RoundTripBus roundTripBuses[6] = {

    RoundTripBus(10, 30, 0),
    RoundTripBus(11, 00, 0),
    RoundTripBus(11, 30, 0),
    RoundTripBus(13, 00, 0),
    RoundTripBus(13, 30, 0),
    RoundTripBus(14, 00, 0),
    };
    

    
    
    for (auto& bus : circulBuses)
    {

        if (bus.isDriving())
        {
            //bus.print_current_location();
            break;
        }
        else
        {
            bus.~CircularBus();
        }

        circularbus_index++;
        
    }
    
    
    for (auto& bus : roundTripBuses)
    {
      

        if (bus.isDriving())
        {
           // bus.print_current_location();
            break;
        }
        else
        {
            bus.~RoundTripBus();
        }
        roundTripBuses_index++;
    }
    

    //circulBuses[circularbus_index].print_info();
    //roundTripBuses[roundTripBuses_index].print_info();
    //cout << start <<"에서 가장 가까운 정류장:"<< me.findStartBusStop() << endl;
    //cout << target << "에서 가장 가까운 정류장:"<<me.findTargetBusStop() << endl;

    if (now < Time(10, 30, 0) || now > Time(14, 30, 00))
    {
        cout << "<버스 운행시간이 아닙니다.>";
        exit(0);
    }

    cout << endl << endl << endl;
    
    if (circulBuses[circularbus_index].is_having_BusStop(me.findStartBusStop()))
    {
        if (circulBuses[circularbus_index].calcul_time(circulBuses[circularbus_index].get_current_loacation(), me.findStartBusStop()) <= Time(0, 0, 0))
        {
            cout << "<버스가 가장 가까운 정류장을 지나쳤습니다. 걸어가세요>" << endl << endl << endl;
            exit(0);
        }
        else if (circulBuses[circularbus_index].calcul_time(circulBuses[circularbus_index].get_current_loacation(), me.findStartBusStop()) < me.getStartWalkingTime(me.findStartBusStop())) //정류장까지 걸어가는 동안 버스가 지나치는 경우
        {
            cout << "<버스 정류장 " << me.findStartBusStop() << "까지  걸어가는 동안 버스가 정류장을 지나갈테니 목적지까지 그냥 걸어가세요>" << endl << endl << endl;

            cout << "버스 현재 위치:" << circulBuses[circularbus_index].get_current_loacation() << endl;
            cout << "타야할 버스 정류장 위치:" << me.findStartBusStop() << endl;
            cout << "걸어서 " << me.findStartBusStop() << "까지 가는데 걸리는 시간: " << me.getStartWalkingTime(me.findStartBusStop()) << endl;
            cout << "버스가 " << me.findStartBusStop() << "까지 오는데 남은 시간 " << circulBuses[circularbus_index].calcul_time(circulBuses[circularbus_index].get_current_loacation(), me.findStartBusStop()) << endl;

        }
        else
        {
            bus_using_time += circulBuses[circularbus_index].calcul_time(circulBuses[circularbus_index].get_current_loacation(), me.findStartBusStop()); //버스를 기다리는 시간을 더함(정류장꺼지 걸어가는 시간은 버스 기다리는 시간에 종속)
            bus_using_time += circulBuses[circularbus_index].calcul_time(me.findStartBusStop(), me.findTargetBusStop());//버스가 목적지 까지 가는데 걸리는 시간
            bus_using_time += me.getTargetWalkingTime(me.findTargetBusStop());//버스 정류장에서 내려서 목적지까지 걸어가는 시간
            only_walk_time = me.getStartWalkingTime(target);


            if (bus_using_time <= only_walk_time)
            {

                cout << "<" << me.findStartBusStop() << " 정류장으로 가서 버스를 타고 " << me.findTargetBusStop() << "에서 내려서" << target << "까지 걸어가는 것이 것이 빠릅니다.>" << endl << endl << endl;
                cout << "버스를 기다리는 시간" << circulBuses[circularbus_index].calcul_time(circulBuses[circularbus_index].get_current_loacation(), me.findStartBusStop()) << endl; //버스를 기다리는 시간
                cout << "버스가" << me.findStartBusStop() << "에서" << me.findTargetBusStop() << "까지 가는데 걸리는 시간: " << circulBuses[circularbus_index].calcul_time(me.findStartBusStop(), me.findTargetBusStop()) << endl;
                cout << "버스에서 내려서 목적지까지 걸어가는 시간:" << me.getTargetWalkingTime(me.findTargetBusStop()) << endl;
                cout << "버스를 이용하는 총 시간: " << bus_using_time << endl;
                cout << start << "에서" << target << "까지 걸어서만 가는 시간 : " << only_walk_time;
            }
            else
            {
                cout << "<" << start << "에서 " << target << "까지 걸어가는 것이 빠릅니다.>" << endl;
                cout << "총 걸어가는 시간: " << only_walk_time << endl;
                cout << "버스를 이용하는 시간" << bus_using_time << endl;

            }

        }
    }
    else if(roundTripBuses[roundTripBuses_index].is_having_BusStop(me.findStartBusStop()))
    {
        if (roundTripBuses[roundTripBuses_index].calcul_time(roundTripBuses[roundTripBuses_index].get_current_loacation(), me.findStartBusStop()) <= Time(0, 0, 0))
        {
            cout << "<버스가 가장 가까운 정류장을 지나쳤습니다. 걸어가세요>" << endl << endl << endl;
            cout << "debug 2";
            exit(0);
        }
        else if (roundTripBuses[roundTripBuses_index].calcul_time(roundTripBuses[roundTripBuses_index].get_current_loacation(), me.findStartBusStop()) < me.getStartWalkingTime(me.findStartBusStop())) //정류장까지 걸어가는 동안 버스가 지나치는 경우
        {
            cout << "<버스 정류장 " << me.findStartBusStop() << "까지  걸어가는 동안 버스가 정류장을 지나갈테니 목적지까지 그냥 걸어가세요>" << endl << endl << endl;

            cout << "버스 현재 위치:" << roundTripBuses[roundTripBuses_index].get_current_loacation() << endl;
            cout << "타야할 버스 정류장 위치:" << me.findStartBusStop() << endl;
            cout << "걸어서 " << me.findStartBusStop() << "까지 가는데 걸리는 시간: " << me.getStartWalkingTime(me.findStartBusStop()) << endl;
            cout << "버스가 " << me.findStartBusStop() << "까지 오는데 남은 시간 " << roundTripBuses[roundTripBuses_index].calcul_time(roundTripBuses[roundTripBuses_index].get_current_loacation(), me.findStartBusStop()) << endl;

        }
        else
        {
            bus_using_time += roundTripBuses[roundTripBuses_index].calcul_time(roundTripBuses[roundTripBuses_index].get_current_loacation(), me.findStartBusStop()); //버스를 기다리는 시간을 더함(정류장꺼지 걸어가는 시간은 버스 기다리는 시간에 종속)
            bus_using_time += roundTripBuses[roundTripBuses_index].calcul_time(me.findStartBusStop(), me.findTargetBusStop());//버스가 목적지 까지 가는데 걸리는 시간
            bus_using_time += me.getTargetWalkingTime(me.findTargetBusStop());//버스 정류장에서 내려서 목적지까지 걸어가는 시간
            only_walk_time = me.getStartWalkingTime(target);


            if (bus_using_time <= only_walk_time)
            {

                cout << "<" << me.findStartBusStop() << " 정류장으로 가서 버스를 타고 " << me.findTargetBusStop() << "에서 내려서" << target << "까지 걸어가는 것이 것이 빠릅니다.>" << endl << endl << endl;
                cout << "버스를 기다리는 시간" << roundTripBuses[roundTripBuses_index].calcul_time(roundTripBuses[roundTripBuses_index].get_current_loacation(), me.findStartBusStop()) << endl; //버스를 기다리는 시간
                cout << "버스가" << me.findStartBusStop() << "에서" << me.findTargetBusStop() << "까지 가는데 걸리는 시간: " << roundTripBuses[roundTripBuses_index].calcul_time(me.findStartBusStop(), me.findTargetBusStop()) << endl;
                cout << "버스에서 내려서 목적지까지 걸어가는 시간:" << me.getTargetWalkingTime(me.findTargetBusStop()) << endl;
                cout << "버스를 이용하는 총 시간: " << bus_using_time << endl;
                cout << start << "에서" << target << "까지 걸어서만 가는 시간 : " << only_walk_time;
            }
            else
            {
                cout << "<" << start << "에서 " << target << "까지 걸어가는 것이 빠릅니다.>" << endl;
                cout << "총 걸어가는 시간: " << only_walk_time << endl;
                cout << "버스를 이용하는 시간" << bus_using_time << endl;

            }

        }

    }
    else
    {
        cout << "버스가 운행하는 시간이 아닙니다" << endl;
    }
    
    
   
        
   
    
    

}