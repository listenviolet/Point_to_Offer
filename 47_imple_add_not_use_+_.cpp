class Solution {
public:
    int Add(int num1, int num2)
    {
        int sum, carry;
        while (num2 != 0)
        {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;
            
            num1 = sum;
            num2 = carry;
        }
        
        return num1;
    }
};

// 写一个函数，求两个整数之和，
// 要求在函数体内不得使用+、-、*、/四则运算符号。

// 运行时间：4ms
// 占用内存：480k

// Notice:
// return num1 not Sum;
// when num2 != 0, it will be in while, the sum and num1 are same
// when num2 == 0, it won't be in while, or num1 keep the last in while sum.
// eg. input 3, 0
