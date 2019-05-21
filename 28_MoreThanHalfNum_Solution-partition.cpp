# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.size() == 0) return 0;
        
        int middle = numbers.size() >> 1;
        int start = 0, end = numbers.size() - 1;
        int index = Partition(numbers, start, end);
        while(index != middle)
        {
            if(index > middle)
            {
                end = index - 1;
                index = Partition(numbers, start, end);
            }
            
            else
            {
                start = index + 1;
                index = Partition(numbers, start, end);
            }
        }
        
        int result = numbers[middle];
        if(!CheckMoreThanHalf(numbers, result)) return 0;
        return result;
    }
    
    bool CheckMoreThanHalf(vector<int>numbers, int result)
    {
        int times = 0;
        for(int i = 0; i < numbers.size(); ++i)
        {
            if(numbers[i] == result) ++times;
        }
        
        bool isMoreThanHalf = false;
        if(times * 2 > numbers.size()) isMoreThanHalf = true;
        return isMoreThanHalf;
    }
    
    int Partition(vector<int> numbers, int start, int end)
    {
        int pivot = numbers[0];
        int left = start, right = end;
        while(left < right)
        {
            while(numbers[right] > pivot && left < right)
            {
                right--;
            }
            
            if(right > left)
            {
                numbers[left] = numbers[right];
                left++;
            }
            
            while(numbers[left] <= pivot && left < right)
            {
                left++;
            }
            
            if(right < left)
            {
                numbers[right] = numbers[left];
                right--;
            }
        }
        
        if(left == right)
        {
            numbers[left] = pivot;
        }
        cout << "---Partition start = " << start << " end = " << end << " index = " << left << endl;
        return left;
    }
};

int main()
{
    int n;
    vector<int> numbers;
    int number;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> number;
        numbers.push_back(number);
    }

    Solution solution;
    int result = solution.MoreThanHalfNum_Solution(numbers);
    cout << result << endl;
    return 0;
}

// 数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。
// 例如输入一个长度为9的数组{1,2,3,2,2,2,5,4,2}。
// 由于数字2在数组中出现了5次，超过数组长度的一半，因此输出2。如果不存在则输出0。

// 运行时间：5ms

// 占用内存：580k