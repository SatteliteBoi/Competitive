#include "string"
#include "vector"
#include "iostream"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string prefix = "";
        int len = strs.size();
        if (len == 0)
        {
            return "";
        }
        string s = strs[0];
        prefix = s;
        for (int i = 1; i < len; i++)
        {
            s = strs[i];
            if (prefix[0] != s[0])
            {
                return "";
            }

            int thisstrlen = s.size();
            int secondlooplegnth;
            thisstrlen > prefix.size() ? secondlooplegnth = prefix.size() : secondlooplegnth = thisstrlen;
            bool completematch = true;
            for (size_t j = 0; j < secondlooplegnth; j++)
            {
                if (s[j] != prefix[j])
                {
                    prefix = prefix.substr(0, j);
                    completematch = false;
                    break;
                }
            }
            if (completematch)
            {
                prefix.resize(secondlooplegnth);
            }
        }
        return prefix;
    }
};