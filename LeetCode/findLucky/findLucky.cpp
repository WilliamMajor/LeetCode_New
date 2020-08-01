// findLucky.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

using namespace std;

int FindLucky(vector<int>& arr);
int luckyArray[505];
int main()
{
    vector<int> testcase{ 2, 2, 3, 4 };

    int output = FindLucky(testcase);
}

int FindLucky(vector<int>& arr)
{ 
    for (int i = 0; i < 501; i++) luckyArray[i] = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        luckyArray[arr[i]]++;
    }

    int luckyNumber = -1;

    for (int i = 500; i >= 1; i--)
    {
        if (luckyArray[i] == i)
        {
            luckyNumber = i;
            break;
        }
    }

    arr.clear();
    return luckyNumber;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
