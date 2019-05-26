class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if(index <= 0) return 0;
        int *pUglyNumbers = new int[index];
        pUglyNumbers[0] = 1;
        int nextUglyIndex = 1;
        
        int *p2 = pUglyNumbers;
        int *p3 = pUglyNumbers;
        int *p5 = pUglyNumbers;
        
        while(nextUglyIndex < index)
        {
            int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
            pUglyNumbers[nextUglyIndex] = min;
            
            while(*p2 * 2 <= pUglyNumbers[nextUglyIndex]) ++p2;
            while(*p3 * 3 <= pUglyNumbers[nextUglyIndex]) ++p3;
            while(*p5 * 5 <= pUglyNumbers[nextUglyIndex]) ++p5;
            
            ++nextUglyIndex;
        }
        
        int ugly = pUglyNumbers[nextUglyIndex - 1];
        delete[] pUglyNumbers;
        return ugly;
    }
    
    int Min(int n1, int n2, int n3)
    {
        int min = (n1 < n2) ? n1 : n2;
        min = (min < n3) ? min : n3;
        return min;
    }
};

// 题目描述
// 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
// 例如6、8都是丑数，但14不是，因为它包含质因子7。 
// 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

// use a list to record the already found ugly numbers;
// use *p2, *p3, *p5 to record the first number 
// that multi its ugly number will > the last one in UglyNumbers list

// get the min(*p2 * 2, *p3 * 3, *p5 * 5) 
// to be the next ugly number and record in UglyNUmbers

// 运行时间：4ms

// 占用内存：476k