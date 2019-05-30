class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() == 0) return;
        int result_exclusive_or = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            result_exclusive_or ^= data[i];
        }
        unsigned int indexof1 = findFirstBitIs1(result_exclusive_or);
        
        *num1 = *num2 = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            if(isBit1(data[i], indexof1))
                *num1 ^= data[i];
            else *num2 ^= data[i];
        }
    }
    
    unsigned int findFirstBitIs1(int number)
    {
        int index = 0;
        while((number & 1) == 0 && (index < 8 * sizeof(int)))
        {
            number = number >> 1;
            ++index;
        }
        return index;
    }
    
    bool isBit1(int number, int index)
    {
        number = number >> index;
        return (number & 1);
    }
};

// 一个整型数组里除了两个数字之外，其他的数字都出现了两次。
// 请写程序找出这两个只出现一次的数字。

// 运行时间：3ms
// 占用内存：500k