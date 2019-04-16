# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return helper(sequence, 0, sequence.size(), INT_MIN, INT_MAX);
    }
    
    bool helper(vector<int> sequence, int start, int last, int low, int high)
    {
        if(start == last) return true;
        int root = sequence[last - 1];
        int Min = *min_element(begin(sequence) + start, begin(sequence) + last);
        int Max = *max_element(begin(sequence) + start, begin(sequence) + last);

        cout << "start = " << start << " last = " << last << " Min = " << Min << " Max = " << Max << " low = " << low << " high = " << high << endl;


        if(Min <= low || Max >= high) return false;
        
        int left = start;
        while(sequence[left] < root)
        {
            left++;
        }

        for(int i = left; i < last; ++i)
        {
            if(sequence[i] < root) return false;
        }

        
        bool flag = false;
        // left subtree
        flag = helper(sequence, start, left, low, root);
        cout << "start = " << start << " last = " << last << " left = " << left << " flag = " << flag << endl;
        if(flag == false) return false;
        else
        {
            flag = helper(sequence, left, last - 1, root, high);
            return flag;
        }
    }
};

int main()
{
    Solution solution;
    int nums[] = {4,8,6,12,16,14,10};
    int nums_length = sizeof(nums) / sizeof(nums[0]);
    vector<int> sequence(nums, nums + nums_length);
    bool flag = solution.VerifySquenceOfBST(sequence);
    cout << flag << endl;
    return 0;
}

// 3. 二叉搜索树的后序
// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 运行时间：3ms

// 占用内存：376k