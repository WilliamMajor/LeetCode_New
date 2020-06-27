class Solution {
public:
    int reverse(int x) {
        long solution = 0;
        int temp = 0;

        for (int i = 0; i < 10; i++)
        {
            temp = x % 10;
            if (((solution * 10 + temp) > 2147483648) || (solution * 10 + temp) < -2147483648)
            {
                return 0;
            }
            else
            {
                solution = (10 * solution) + temp;
            }

            x /= 10;
            if (x == 0)
            {
                break;
            }
        }
        return (int)solution;

    }
};
