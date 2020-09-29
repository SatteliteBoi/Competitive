#include <math.h>
#include <iostream>
using namespace std;


class Solution
{
public:
    bool isPalindrome(int x)
    {
        int m = x, t = x;
        int i = 0;
        bool ans = true;
        if(x==0)
        {
            return true;
        }
        if (x < 0 || x % 10 == 0)
        {
            return false;
        }
        if (x / 10 < 1)
        {
            return true;
        }
        while (t >= 1)
        {
            i++;
            t = t / 10;
        }
        for (int inc = 1; inc<i; inc++){
            int mult = pow(10, i - inc);
            int l = m % 10;
            int n = x / mult;
            m = m / 10;
            x = x % mult;
            if (l != n)
            {
                ans = false;
                break;
            }
        }

        return ans;
    }
};