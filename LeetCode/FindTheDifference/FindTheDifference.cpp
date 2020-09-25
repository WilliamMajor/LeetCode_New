// FindTheDifference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t)
    {
        char returnCharacter = 0;

        if (s.size() > t.size())
        {
            for (size_t stringIndex = 0; stringIndex < t.size(); stringIndex++)
            {
                returnCharacter ^= (s[stringIndex] ^ t[stringIndex]);
            }
            returnCharacter ^= s[t.size()];
        }
        else
        {
            for (size_t stringIndex = 0; stringIndex < s.size(); stringIndex++)
            {   
                returnCharacter ^= (s[stringIndex] ^ t[stringIndex]);
            }
            returnCharacter ^= t[s.size()];
        }
        return returnCharacter;
    }
};

int main()
{
    Solution test;
    string input0 = "abcd";
    string input1 = "edcba";
    char returnValue = test.findTheDifference(input0, input1);
}

