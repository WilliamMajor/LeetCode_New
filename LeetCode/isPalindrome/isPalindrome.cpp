class Solution {
public:
    bool isPalindrome(int x) {
        int storage = x;
        long  testcase = 0;
        int temp = 0;
        if (x < 0)
            return false;

        for (int i = 0; i < 10; i++)
        {
            temp = x % 10;
            testcase = (10 * testcase) + temp;
            x /= 10;
            if (x == 0)
            {
                break;
            }
        }
        return(testcase == storage);
    }
};