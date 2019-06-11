enum Status {kValid = 0, kInvalid};
class Solution {
public:
    int StrToInt(string str) {
        int g_nStatus = kInvalid;
        long long int Sum = 0;
        if(str.size() == 0) return 0;
        // remove space
        int start = 0;
        for(int i = 0; i < str.size(); ++i)
        {
            if(str[i] == ' ') continue;
            else 
            {
                start = i; break;
            }
        }
        
        // judge +-
        int flag = 1;
        if(str[start] == '-')
        {
            flag = -1;
            start++;
        }
        else if(str[start] == '+') start++;

        if(start == str.size()) return 0; // if "+" or "-", invalid

        int j;
        for(j = start; j < str.size(); ++j)
        {
            if(str[j] > '9' or str[j] < '0') return 0;
            Sum = 10 * Sum + str[j] - '0';

            if((flag == 1 && Sum > 0x7fffffff) || (flag == -1 && Sum < (signed int) 0x80000000))
            {
                return 0;
            }
        }
        if(j == str.size()) g_nStatus = kValid;
        return Sum * flag;
    }
    
};

// 运行时间：4ms
// 占用内存：588k

// 题目描述
// 将一个字符串转换成一个整数(实现Integer.valueOf(string)的功能，
// 但是string不符合数字要求时返回0)，
// 要求不能使用字符串转换整数的库函数。 
// 数值为0或者字符串不是一个合法的数值则返回0。

// 输入描述:
// 输入一个字符串,包括数字字母符号,可以为空

// 输出描述:
// 如果是合法的数值表达则返回该数字，否则返回0

// 示例1
// 输入
// +2147483647
//     1a33
// 输出
// 2147483647
//     0

// Notice:
// use global var to record whether the input is valid '0' or invalid input
// since they all return 0

// Shortcoming:
// 1. invalid or valid return the same value
// 2. "+" "-" set invalid
// 3. overflow or underflow => max + int = 0x7fff ffff; min - int = 0x8000 0000
// 4. set sum be long long int
