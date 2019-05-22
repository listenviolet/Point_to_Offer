# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void display(vector<int> res)
    {
        vector<int>::iterator it;
        for(it = res.begin(); it != res.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() == 0) return res;
        int start = 0, end = input.size() - 1;
        int index = Partition(input, start, end);
        while(index != k - 1)
        {
            if(index > k - 1) 
            {
                index = Partition(input, start, index - 1);
            }
            else if(index < k - 1)
            {
                index = Partition(input, index + 1, end);
            }
        }
        
        for(int i = 0; i < k; ++i)
        {
            res.push_back(input[i]);
        }
        
        return res;
    }
    
    int Partition(vector<int> &input, int start, int end)
    {
        int left = start, right = end;
        if(left == right) return left;
        int pivot = input[start];
        
        while(left < right)
        {
            while(input[right] > pivot && left < right)
            {
                right--;
            }
            if(left < right)
            {
                input[left] = input[right];
                left++;
            }
            
            while(input[left] < pivot && left < right)
            {
                left++;
            }
            
            if(left < right)
            {
                input[right] = input[left];
                right--;
            }
        }
        
        if(left == right) input[left] = pivot;
        cout << "After Partition:" << endl;
        display(input);
        return left;
    }
private:
    vector<int> res;
};


int main()
{
    int n, k;
    vector<int> input;
    vector<int> res;
    
    cin >> n >> k;
    int number;

    for(int i = 0; i < n; ++i)
    {
        cin >> number;
        input.push_back(number);
    }

    Solution solution;
    res = solution.GetLeastNumbers_Solution(input, k);

    solution.display(res);
    return 0;
}

// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，
// 则最小的4个数字是1,2,3,4,。

// 运行时间：5ms

// 占用内存：476k

// Note:
// int pivot = input[start]; not input[0]
// do not forget:
// if(left == right) input[left] = pivot;