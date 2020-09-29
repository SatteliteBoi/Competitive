#include <map>
#include <string>

using namespace std;


class Solution
{
public:
    int romanToInt(string s){
        int ans = 0;
        map<char, int> romannumbers = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i<s.size(); i++)
        {
            char c = s[i];
            if (romannumbers.find(c)->second < romannumbers.find(s[1+i])->second)
            {
                ans += romannumbers.find(s[i+1])->second - romannumbers.find(s[i])->second;
                i++;
            }
            else{
                ans += romannumbers.find(c)->second;
            }
        }
        return ans;
    }
};