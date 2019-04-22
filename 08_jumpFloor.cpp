class Solution {
public:
    int jumpFloor(int number) {
        int f[3] = {1, 1, 2};
        if(number <= 2) return f[number];
        int f_minus_one = 2;
        int f_minus_two = 1;
        int f_n = 0;
        for(int i = 3; i <= number; ++i)
        {
            f_n = f_minus_one + f_minus_two;
            
            f_minus_two = f_minus_one;
            f_minus_one = f_n;
        }
        return f_n;
    }
};

// 运行时间：3ms

// 占用内存：468k

// 8. 跳台阶
// 一只青蛙一次可以跳上1级台阶，也可以跳上2级。
// 求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。