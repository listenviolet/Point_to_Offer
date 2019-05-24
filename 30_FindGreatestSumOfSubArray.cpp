# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0) return 0;
        vector<int> tmp(array.size(), 0);
        int Max;

        Max = array[0];
        for(int i = 0; i < array.size(); ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                tmp[j] += array[i];
                if(Max < tmp[j]) Max = tmp[j];
            }
        }    
        return Max;
    }
};

int main()
{
    int n, number;
    vector<int> array;
    cin >> n;
    for(int i = 0; i < n; ++i)
    {
        cin >> number;
        array.push_back(number);
    }
    Solution solution;
    int Max = solution.FindGreatestSumOfSubArray(array);
    cout << Max << endl;
    return 0;
}

// 连续子数组的最大和

// HZ测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
// 当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 给一个数组，返回它的最大连续子序列的和.(子向量的长度至少是1)

// 运行时间：4ms
// 占用内存：612k