# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        if(str.size() == 0) return str;
        reverse(str, 0, str.size() - 1);
        int start = 0, end = start;
        while(end < str.size())
        {
            int i = start;
            while(i < str.size() && str[i] != ' ') ++i;
            // cout << "i - 1 = " << i - 1 << endl;
            if(i - 1 >= 0)reverse(str, start, i - 1);
            start = i + 1;
            end = start;
            // cout << "new start = " << start << endl;
        }
        return str;
    }
    
    void reverse(string &str, int l, int r)
    {
        // cout << "l = " << l << " r = " << r << endl;
        char tmp;
        for(int i = 0; i <= (r - l) / 2; ++i)
        {
            tmp = str[l + i];
            str[l + i] = str[r - i];
            str[r - i] = tmp;
        }
        // cout << "In reverse =" << str << endl;
    }
};

int main()
{
    string str;
    Solution solution;
    while(getline(cin, str))
    {
        str = solution.ReverseSentence(str);
        cout << str << endl;
    }
    return 0;

    // getline(cin, str);
    // for(int i = 0; i < str.size(); ++i)
    // {
    //     if(str[i] == ' ') cout << "#";
    //     else cout << str[i];
    // }
    // cout << endl;
    // int i = 0;
    // while(i < str.size() && str[i] != ' ') ++i;
    // cout << i - 1 << endl;
    // return 0;
}

// 运行时间：5ms

// 占用内存：584k

// hi#
// reverse: #ih
// i = 0 -> i - 1 = -1 cannot be reversed as separate word
// so if i - 1 < 0 skip

