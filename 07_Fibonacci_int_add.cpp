class Solution {
public:
    int Fibonacci(int n) {
        int f[2] = {0, 1};
        if(n < 2) return f[n];
        
        long long f_minus_one = 1;
        long long f_minus_two = 0;
        
        long long f_n = 0;
        
        for(int i = 2; i <= n; ++i)
        {
            f_n = f_minus_one + f_minus_two;
           
            f_minus_two = f_minus_one;
            f_minus_one = f_n;
        }
        
        return f_n;
    }
};


// 运行时间：3ms
// 占用内存：472k