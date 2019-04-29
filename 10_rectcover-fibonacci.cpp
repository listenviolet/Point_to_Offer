class Solution {
public:
    int rectCover(int number) {
        if(number == 0) return 0;
        if(number == 1) return 1;
        if(number == 2) return 2;
        int minus_one = 2;
        int minus_two = 1;
        int res = 0;
        for(int i = 3; i <= number; ++i)
        {
            res = minus_one + minus_two;
            minus_two = minus_one;
            minus_one = res;
        }
        return res;
    }
};

// 题目描述
// 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
// 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？

// 运行时间：5ms
// 占用内存：452k