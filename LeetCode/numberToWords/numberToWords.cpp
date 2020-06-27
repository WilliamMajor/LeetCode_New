#include <iostream>
#include <string>

using namespace std;

string numberToWords(int num);
string getIntermediate(int num);
string BigKeywords[4] = { "Billion", "Million", "Thousand", "Hundred" };
string MediumKeywords[10] = { "", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };
string LittleKeywords[20] = { "","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
                            "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
                            "Eighteen", "Nineteen" };

int main()
{
    string result = numberToWords(1000);
    cout << result;

    return 0;
}

string numberToWords(int num)
{
    string rtnString = "";
    
    if (num == 0)
        return "Zero";

    int workingNumber = num / 1000000000;
    if (workingNumber != 0)
        rtnString += LittleKeywords[workingNumber] + " " + BigKeywords[0] + " ";

    workingNumber = num % 1000000000;
    workingNumber /= 1000000;
    if (workingNumber != 0)
        rtnString += getIntermediate(workingNumber) + " " + BigKeywords[1] + " ";

    workingNumber = num % 1000000;
    workingNumber /= 1000;
    if (workingNumber != 0)
        rtnString += getIntermediate(workingNumber) + " " + BigKeywords[2] + " ";

    workingNumber = num % 1000;
    rtnString += getIntermediate(workingNumber);

    if (rtnString.back() == ' ')
        rtnString.pop_back();

    return rtnString;
}

string getIntermediate(int num)
{
    string rtnString = "";
    int workingNumber = num;

    workingNumber /= 100;
    if (workingNumber != 0)
    {
        if (num % 100 != 0)
            rtnString += LittleKeywords[workingNumber] + " " + BigKeywords[3] + " ";
    }

    workingNumber = num % 100;
    workingNumber /= 10;
    if (workingNumber != 0)
    {
        if (workingNumber != 1)
            rtnString += MediumKeywords[workingNumber] + " " + LittleKeywords[num % 10];
       else
        {
            workingNumber = num % 20;
            rtnString += LittleKeywords[workingNumber];
        }

    }
    if (num % 100 < 10)
    {
        workingNumber = num % 10;
        rtnString += LittleKeywords[workingNumber];
    }


    return rtnString;
}

