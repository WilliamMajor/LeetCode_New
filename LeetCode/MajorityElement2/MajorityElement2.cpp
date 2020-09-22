// MajorityElement2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int>& nums)
    {
        vector<int> returnVector;
        unordered_map<int, int> tracker;
        double qualify = nums.size() / 3;
        for (int element : nums)
        {
            if (tracker.find(element) == tracker.end())
            {
                tracker.insert(pair<int, int>(element, 1));
            }
            else
            {
                tracker[element]++;
            }
        }
        for (auto value : tracker)
        {
            if (value.second > qualify)
            {
                returnVector.push_back(value.first);
            }
        }
        return returnVector;
    }
    
};

int main()
{
    Solution testSolution;
    vector<int> test = { 3,2,3 };
    vector<int> output = testSolution.majorityElement(test);
}

