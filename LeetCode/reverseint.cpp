#include <cmath>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        bool negative = true;
        if (x == 0)
        {
            return 0;
        }
        else if (x > 0)
        {
            negative = false;
        }
        int m = abs(x);
        int ans = 0;

        while (m > 0)
        {
            if (ans > 214748364.6)
            {
                return 0;
            }
            else
            {
                ans = ans * 10;
                ans += m % 10;
                m = m / 10;
            }
        }

        return negative ? -ans : ans;
    }
};