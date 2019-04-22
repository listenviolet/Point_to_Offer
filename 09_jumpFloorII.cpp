class Solution {
public:
    int jumpFloorII(int number) {
        int f[1000];
        f[0] = 1;
        f[1] = 1;
        if(number < 2) return f[number];
        for(int i = 2; i <= number; ++i)
        {
            int temp = 0;
            for(int j = 0; j < i; ++j)
            {
                temp += f[j];
            }
            f[i] = temp;
        }
        
        return f[number];
    }
};

// 9.变态跳台阶
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法。

// 运行时间：5ms

// 占用内存：504k