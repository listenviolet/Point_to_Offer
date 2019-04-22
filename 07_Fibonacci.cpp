# include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int Fibonacci(int n) {
        int f[45];
        // memset(f, 0, sizeof(f));
        f[0] = 0;
        f[1] = 1;
        if(n == 0 || n == 1) return f[n];
        for(int i = 2; i <= n; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
    
};

int main()
{
    Solution solution;
    cout << solution.Fibonacci(3) << endl;
    return 0;
}

// 运行时间：7ms

// 占用内存：596k

// 7. 斐波那契数列
// 现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
// n<=39