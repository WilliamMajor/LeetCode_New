#pragma once
#include <iostream>
#include <map>
//#include "Passenger.h"

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

class Connection
{
public:
    double timesMade;
    string connectionID;
    double avgTime;

    Connection()
    {
        timesMade = 0;
        connectionID = "";
        avgTime = 0;
    }

    Connection(string connectionIDArg)
    {
        timesMade = 0;
        avgTime = 0;
        connectionID = connectionIDArg;
    }

};

class UndergroundSystem 
{
public:
    map<string, Connection> connection;
    map<int, Passenger> passengers;
    UndergroundSystem()
    {

    }

    void checkIn(int id, string stationName, int t)
    {
        Passenger newRider = Passenger(id, stationName, t);
        passengers.insert(pair<int, Passenger>(id, newRider));
    }

    void checkOut(int id, string stationName, int t)
    {
        string connectionName = passengers[id].startingStation + stationName;
        double tripDuration = ((double)t - (double)(passengers[id].boardingTime));
        if (connection.find(connectionName) == connection.end())
        {
            Connection connectionObj = Connection(connectionName);
            connectionObj.timesMade++;
            connectionObj.avgTime = tripDuration;
            connection.insert(pair<string, Connection>(connectionObj.connectionID, connectionObj));
        }
        else
        {
            connection[connectionName].avgTime = (connection[passengers[id].startingStation +
                stationName].avgTime * connection[connectionName].timesMade + tripDuration) /
                (connection[connectionName].timesMade + 1.0);

            connection[connectionName].timesMade++;
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        return connection[startStation + endStation].avgTime;
    }
};



