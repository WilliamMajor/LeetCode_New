// hasAllCodes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

bool hasAllCodes(string s, int k);

int main()
{
    bool result = hasAllCodes("0101", 13);
}

bool hasAllCodes(string s, int k)
{
    int num = 1 << k;
    if (s.size() < num + k - 1)
        return false;
    vector<char> temp(num, 0);
    int x = num - 1;

    int value = 0;
    for (int i = 0; i < k; i++) {
        value = (value << 1) + s[i] - '0';
    }

    temp[value] = 1;
    int ret = 1;

    for (int i = k; i < s.size(); i++) {
        value = ((value << 1) + s[i] - '0') & x;
        ret += temp[value] == 0;
        temp[value] = 1;
        if (ret == num)
            return true;
    }
    return false;
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
