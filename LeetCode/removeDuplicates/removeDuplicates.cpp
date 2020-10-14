// removeDuplicates.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    //Solution that does not just use the unique function, because thats boring.
    int removeDuplicates(vector<int>& nums)
    {
        set<int> storage;
        for (auto value : nums)
        {
            storage.insert(value);
        }
        nums.clear();
        for (auto value : storage)
        {
            nums.push_back(value);
        }
            
        return storage.size();
    }
};



int main()
{
    Solution testCase;
    vector<int> nums = { 1,1,2 };
    testCase.removeDuplicates(nums);

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
