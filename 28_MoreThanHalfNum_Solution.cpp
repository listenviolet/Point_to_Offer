class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        sort(numbers.begin(), numbers.end());
        int mid_index = (numbers.size() - 1) / 2;
        int i = mid_index;
        int count = 0;
        while(i >= 0)
        {
            if(numbers[i] == numbers[mid_index])
            {
                count++;
                i--;
            }
            else break;
        }
        
        i = mid_index + 1;
        while(i < numbers.size())
        {
            if(numbers[i] == numbers[mid_index])
            {
                count++;
                i++;
            }
            else break;
        }
        
        if(count > numbers.size() / 2) return numbers[mid_index];
        else return 0;
    }
    
    
};

// 题目描述
// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

// 运行时间：5ms

// 占用内存：632k