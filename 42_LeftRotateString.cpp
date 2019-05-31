# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        if(str.size() == 0) return str;
	n = n % str.size(); 
        if(n == 0) return str;
        reverse(str, 0, str.size() - 1);
        reverse(str, str.size() - n, str.size() - 1);
        reverse(str, 0, str.size() - n - 1);
        return str;
    }
    
    void reverse(string &str, int l, int r)
    {
        char tmp;
        for(int i = 0; i <= (r - l) / 2; ++i)
        {
            tmp = str[l + i];
            str[l + i] = str[r - i];
            str[r - i] = tmp;
        }
    }
};

int main()
{	
	Solution solution;
	string str;
	int n;
	while(cin >> str >> n)
	{	
		str = solution.LeftRotateString(str, n);
		cout << str << endl;
	}
	return 0;
}

// 汇编语言中有一种移位指令叫做循环左移（ROL），
// 现在有个简单的任务，就是用字符串模拟这个指令的运算结果。
// 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
// 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，
// 即“XYZdefabc”。是不是很简单？OK，搞定它！

// 运行时间：3ms
// 占用内存：460k

// Notice:
// n = 0
// n >= str.size() => n %= str.size()
