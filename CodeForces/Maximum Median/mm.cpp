#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int k;


vector<int> readinput(int n)
{
    vector <int> arr = {};
    int m;
    for (int i = 0; i<n; i++)
    {
        cin>>m;
        arr.push_back(m);
    }
    return arr;
}

bool increment(vector<int> &numbers, int i)
{
    for (int j = i; j >= 0; j--)
    {
        int &x = numbers[j];
        x++;
        k--;
        if (k <= 0)
        {
            return false;
        }
    }
    return true;
}

void magic(vector<int> &numbers, int i)
{

    if(numbers.size()==i+1)
    {
        bool keepgoing = true;
        while (keepgoing)
        {
            keepgoing = increment(numbers, i);
        }
        return;
    }
    else{
        while(numbers[i]<numbers[i + 1] && k > 0)
        {
            bool cancontinue = increment(numbers, i);
        }
        return;
    }
}


int main(void)
{
    int n;
    cin >> n >> k;
    vector<int> allnumbers = readinput(n);
    sort(allnumbers.begin(), allnumbers.end());
    vector<int> righthalf(allnumbers.begin()+n/2,allnumbers.end());
    int i = 0;
    while (k>0)
    {
        magic(righthalf, i);
        i++;
    }
        

    cout << righthalf[0];
}