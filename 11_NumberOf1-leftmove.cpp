class Solution {
public:
    int  NumberOf1(int n) {
        int count = 0;
        uint flag = 1;
        while(flag >= 1)
        {
            if((n & flag) > 0)
            {
             count++;
            }

            flag = flag << 1;
        }
        return count;
    }
};

// 输入一个整数，输出该数二进制表示中1的个数。
// 其中负数用补码表示。
// alg:
// 这里的flag为uint类型，在int的范围内，均为正数；
// 超出int范围可能为复数；
// 以flag >= 0 为判断移位的终止条件。

// 这个解法中循环的次数等于整数二进制的位数，
// 32位的整数需要循环32次。

// 运行时间：4ms
// 占用内存：476k