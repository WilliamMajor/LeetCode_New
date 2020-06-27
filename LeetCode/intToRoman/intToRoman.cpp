#include <iostream>

using namespace std;

string intToRoman(int num);

int main()
{
    string result = intToRoman(58);
    cout << result;

    return 0;
}

string intToRoman(int num)
{
    string rtnString = "";

    int numInUse = num / 1000;

    if (numInUse != 0)
    {
        if (numInUse > 0 && numInUse <= 3)
        {
            for (int idx = 0; idx < numInUse; idx++)
                rtnString += "M";
        }
        else if (numInUse == 4)
        {
            rtnString += "MV";
        }
        else if (numInUse == 9)
        {
            rtnString += "IX";
        }
        else
        {
            rtnString += "V";
            for (int idx = 0; idx < (numInUse - 5); idx++)
            {
                rtnString += "M";
            }
        }
    }


    num = num % 1000;

    numInUse = num / 100;
    if (numInUse != 0)
    {
        if (numInUse > 0 && numInUse <= 3)
        {
            for (int idx = 0; idx < numInUse; idx++)
                rtnString += "D";
        }
        else if (numInUse == 4)
        {
            rtnString += "CD";
        }
        else if (numInUse == 9)
        {
            rtnString += "CM";
        }
        else
        {
            rtnString += "D";
            for (int idx = 0; idx < (numInUse - 5); idx++)
            {
                rtnString += "C";
            }
        }
    }


    num = num % 100;
    numInUse = num / 10;
    if (numInUse != 0)
    {
        if (numInUse > 0 && numInUse <= 3)
        {
            for (int idx = 0; idx < numInUse; idx++)
                rtnString += "X";
        }
        else if (numInUse == 4)
        {
            rtnString += "XL";
        }
        else if (numInUse == 9)
        {
            rtnString += "XC";
        }
        else
        {
            rtnString += "L";
            for (int idx = 0; idx < (numInUse - 5); idx++)
            {
                rtnString += "X";
            }
        }
    }


    num = num % 10;
    numInUse = num;
    if (numInUse != 0)
    {
        if (numInUse > 0 && numInUse <= 3)
        {
            for (int idx = 0; idx < numInUse; idx++)
                rtnString += "I";
        }
        else if (numInUse == 4)
        {
            rtnString += "IV";
        }
        else if (numInUse == 9)
        {
            rtnString += "IX";
        }
        else
        {
            rtnString += "V";
            for (int idx = 0; idx < (numInUse - 5); idx++)
            {
                rtnString += "I";
            }
        }
    }

    return rtnString;
}