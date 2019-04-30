class Solution {
public:
    void reOrderArray(vector<int> &array) {
        int i = 0, j = 0;
        while(i < array.size() && j < array.size())
        {
            while(i < array.size() && array[i] % 2) ++i;
            while(j < array.size() && array[j] % 2 == 0) ++j;
            if(i >= array.size() || j >= array.size()) return;
            if(i >= j)
            {
                ++j;
                continue;
            }
            int odd = array[j];
            for(int k = j; k > i; --k)
            {
                array[k] = array[k - 1];
            }
            array[i] = odd;
            
            ++i;
            ++j;
        }
    }
};

// 调整数组顺序使奇数位于偶数前面

// 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，
// 使得所有的奇数位于数组的前半部分，
// 所有的偶数位于数组的后半部分，
// 并保证奇数和奇数，偶数和偶数之间的相对位置不变。

// 运行时间：5ms

// 占用内存：456k