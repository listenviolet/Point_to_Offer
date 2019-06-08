class A;
A* Array[2];
class A
{
public: 
    virtual unsigned int Sum(unsigned int n)
    {
        return 0;
    }
};

class B:public A
{
public:
    virtual unsigned int Sum(unsigned int n)
    {
        return Array[!!n] -> Sum(n - 1) + n;
    }
};
class Solution {
public:
    int Sum_Solution(int n) {
        A a;
        B b;
        Array[0] = &a;
        Array[1] = &b;
        int value = Array[1] -> Sum(n);
        return value;
    }
};

// 求1+2+3+...+n，要求不能使用乘除法、
// for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

// 运行时间：4ms
// 占用内存：480k