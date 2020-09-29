#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {

        int opencount = 0;
        int closecount = 0;
        stack<int> open;
        queue<int> close;
        int len = s.size();
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                opencount++;
                open.push(s[i]);
            }
            if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                closecount++;
                close.push(s[i]);
            }

            //ANCHOR if every opening bracket is closed correctly
            //ANCHOR the last open bracket must be the first closed bracket
            //ANCHOR if the first opened is the first closed
            //ANCHOR //TODO ONE PASS QUEUESTACK AND QUEUE
            //TODO https://leetcode.com/problems/valid-parentheses/

            if (open.size() != 0 && close.size() != 0)
            {
                if (open.top() == close.front())
                {
                    open.pop();
                    close.pop();
                }
            }
        }

        if (open.size() == 0 && close.size() == 0)
        {
            return true;
        }
        return false;
    }
};

#include <iostream>
#include <vector>

int main(void)
{
    int n;
    cin >> n;
    string input;
    for (int i = 0; i < n; i++)
    {
        char thing;
        cin >> thing;
        input += thing;
    }
    Solution obj;
    string s;
    obj.isValid(input) ? s = "legit" : s = "notlegit";
    cout << s;
}