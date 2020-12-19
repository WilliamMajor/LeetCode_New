// ZigZagConversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        string returnString = "";
        vector<string> tracker(numRows, "");
        int length = s.length();
        int x = 0;
        bool directionIsDown = true;
        if (numRows == 1)
            return s;
        for (int idx = 0; idx < length; idx++)
        {
            tracker[x] += s[idx];
            if (x == numRows - 1 || (x == 0 && idx != 0))
                directionIsDown = !directionIsDown;
            (directionIsDown) ? x++ : x--;
        }
        for (int idx = 0; idx < numRows; idx++)
        {
            returnString += tracker[idx];
        }
        return returnString;
    }
};

int main()
{
    Solution testSolution;
    string test = "AB";
    int numRows = 1;

    string result = testSolution.convert(test, numRows);
}
