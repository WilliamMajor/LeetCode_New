// longestSubstringWithoutRepeatingCharacters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

using namespace std;

int lengthOfLongestSubstring(string s);

int main()
{
    lengthOfLongestSubstring("dvdf");

}


    int lengthOfLongestSubstring(string s) 
    {
        int mm[128] = { 0 };
        int rv = 0;
        int start = 0;
        int idx = 0;
        const char* p = s.data();

        while (*p) {
            idx++;

            start = max(mm[*p], start);
            rv = max(rv, idx - start);

            mm[*p] = idx;
            p++;
        }

        return rv;
    }
