#pragma once
#include <iostream>
#include <unordered_map>

using namespace std;
class UndergroundSystem {
public:
	unordered_map<string, unordered_map<string, pair<int, int>> > mp;
	unordered_map<int, pair<string, int> > person;

	UndergroundSystem() {

	}

	void checkIn(int id, string stationName, int t) {
		person[id] = { stationName, t };
	}

	void checkOut(int id, string stationName, int t) {
		string dest = stationName;
		string start = person[id].first;
		mp[start][dest].first += t - person[id].second;
		mp[start][dest].second++;
	}

	double getAverageTime(string start, string dest) {
		return double(mp[start][dest].first) / double(mp[start][dest].second);
	}
};