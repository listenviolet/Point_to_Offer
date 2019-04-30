class Solution {
public:
    double Power(double base, int exponent) {
        if(exponent == 0) return 1;
        double res = 1;
        if(exponent > 0)
        {
            for(int i = 1; i <= exponent; ++i)
            {
                res *= base;
            }
            return res;
        }
        
        else
        {
            for(int i = 1; i <= -1 * exponent; ++i)
            {
                res *= base;
            }
            return 1 / res;
        }
    }
};


// 给定一个double类型的浮点数base和int类型的整数exponent。
// 求base的exponent次方。

// 运行时间：3ms

// 占用内存：476k