#pragma once
#include <iostream>

using namespace std;

class Passenger
{
public:
    int id;
    int boardingTime;
    string startingStation;

    Passenger(int idArg, string startingStationArg, int boardingTimeArg)
    {
        id = idArg;
        startingStation = startingStationArg;
        boardingTime = boardingTimeArg;
    }

    Passenger()
    {
        id = 0;
        startingStation = "";
        boardingTime = 0;
    }

};