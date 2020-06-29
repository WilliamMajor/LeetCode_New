// underGroundSystem.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "underGroundSystem.h"

using namespace std;

int main()
{
    int id = 1;
    int t = 12;


    UndergroundSystem* obj = new UndergroundSystem();
    obj->checkIn(1, "L", 3);
    obj->checkIn(2, "P", 8);
    obj->checkIn(3, "L", 10);
    obj->checkOut(1, "W", 15);
    obj->checkOut(3, "W", 20);
    obj->checkOut(2, "C", 22);
    double param_3 = obj->getAverageTime("P", "C");
    double param_2 = obj->getAverageTime("L", "W");
    obj->checkIn(4, "L", 24);
    double param_1 = obj->getAverageTime("L", "W");
    obj->checkOut(4, "W", 38);
    double param_0 = obj->getAverageTime("L", "W");
    //obj->checkIn(id++, stationName, 16);
    //stationName += "1";
    //obj->checkOut(id, stationName, 17);


    cout << param_3 << endl;
    
}


