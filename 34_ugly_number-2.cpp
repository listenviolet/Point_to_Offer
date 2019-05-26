#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int ugly_list[] = {2, 3, 5};
        int length = sizeof(ugly_list) / sizeof(ugly_list[0]);
        if(index == 1) return 1;
        int cnt = 1;
        int tmp = 1;
        while(cnt < index)
        {
            tmp++;
            if(isUgly(tmp, ugly_list, length)) 
            {
                cnt++;
            }
        }
        return tmp;
        
    }
    
    int divide(int number, int ugly)
    {
        while(number % ugly == 0)
        {
            number = number / ugly;
        }
        return number;
    }    

    bool isUgly(int number, int *ugly_list, int length)
    {
        for(int i = 0; i < length; ++i)
        {
            number = divide(number, ugly_list[i]);
        }
        if(number == 1) return true;
        else return false;
    }
};


int main()
{
    Solution solution;
    int index;
    while(cin >> index)
    {
        cout << solution.GetUglyNumber_Solution(index) << endl;
    }


    return 0;
}

// Not pass