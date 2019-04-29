class Solution {
public:
     int  NumberOf1(int n) {
         int count = 0;
         while(n)
         {
             count++;
             n = (n - 1) & n;
         }
         return count;
     }
};

// 输入一个整数，输出该数二进制表示中1的个数。
// 其中负数用补码表示。

// alg:
// 把一个整数减去1之后再和原来的整数做位与运算，
// 得到的结果相当于是把整数的二进制表示中的最右边一个1变成0。
// 很多二进制的问题都可以用这个思路解决。

// 运行时间：3ms
// 占用内存：456k