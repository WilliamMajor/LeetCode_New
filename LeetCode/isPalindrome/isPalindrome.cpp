class Solution {
public:
    bool isPalindrome(int x) {
        int storage = x;
        long  testcase = 0;
        int temp = 0;
        if (x < 0)
            return false;

        while (testcase < storage)
        {
            temp = x % 10;
            testcase = (10 * testcase) + temp;
            if ((x /= 10) == 0)
                break;
        }
        return(testcase == storage);
    }
};