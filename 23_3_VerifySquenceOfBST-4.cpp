# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty()) return false;
        return helper(sequence, 0, sequence.size(), INT_MIN, INT_MAX);
    }
    
    bool helper(vector<int> sequence, int start, int last, int min_limit, int max_limit)
    {
        if(start == last) return true;
        int root = sequence[last - 1];
        int Max = *max_element(sequence.begin() + start, sequence.begin() + last);
        int Min = *min_element(sequence.begin() + start, sequence.begin() + last);
        if(Max >= max_limit || Min <= min_limit) return false;
        int i = start;
        while(sequence[i] < root)
        {
            ++i;
        }
        
        return helper(sequence, start, i, min_limit, root) && helper(sequence, i, last - 1, root, max_limit);
    }
};

int main()
{
    Solution solution;
    int n;
    vector<int> sequence;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        int number;
        cin >> number;
        sequence.push_back(number);
    }
    cout << solution.VerifySquenceOfBST(sequence) << endl;
    return 0;
}

// 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。

// 运行时间：3ms

// 占用内存：488k