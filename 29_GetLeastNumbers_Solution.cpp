class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(input.size() == 0 || input.size() < k) return res;
        make_heap(input.begin(), input.end(), greater<int>());
        for(int i = 1; i <= k; ++i)
        {
            res.push_back(input[0]);
            pop_heap(input.begin(), input.end(), greater<int>());
            input.pop_back();
        }
        return res;
    }
private:
    vector<int> res;
};

// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，
// 则最小的4个数字是1,2,3,4,。

// 运行时间：5ms
// 占用内存：476k