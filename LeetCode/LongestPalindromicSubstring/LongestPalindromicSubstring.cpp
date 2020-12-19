// LongestPalindromicSubstring.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    //Idea for how to implement, find all of the tiny palindromes and then use 
    //multithreading to blast through them and just see which one returned the longest string

    string longestPalindrome(string s) 
    {
        string sLongest = "" + s[0];
        string sCurrent = sLongest;
        uint16_t uiStartingIndex = 0;

        if (s.length() == 1)
        {
            return s;
        }
        for (uint16_t uiIndex = 1; uiIndex < s.length(); uiIndex++)
        {
            sCurrent += s[uiIndex];
            if (isPalindrome(sCurrent) || isPalindrome(sCurrent + s[uiIndex + 1]))
            {

            }
        }
    }
    bool isPalindrome(string s)
    {
        uint16_t uiFallingIndex = s.length();
        for (uint16_t uiLeadingIndex = 0; uiLeadingIndex < uiFallingIndex;)
        {
            if (tolower(s[uiLeadingIndex++]) != tolower(s[uiFallingIndex--]))
                return false;
        }
        return true;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}


