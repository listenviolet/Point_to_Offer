#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        if(k <= 0 || k > input.size() || input.size() == 0) return res;
        vector<int>::iterator it;
        multiset<int>::iterator set_iter;
        for(it = input.begin(); it != input.end(); ++it)
        {
            if(leastNumbers.size() < k)
            {
                leastNumbers.insert(*it);
            }
            
            else
            {
                set_iter = leastNumbers.end();
                set_iter--;
                // cout << "current max:" << *set_iter << endl;
                if(*it < *set_iter)
                {
                    leastNumbers.erase(set_iter);
                    leastNumbers.insert(*it);
                }
            }
        }
        
        set_iter = leastNumbers.begin();
        for(set_iter = leastNumbers.begin(); set_iter != leastNumbers.end(); ++set_iter)
        {
            res.push_back(*set_iter);
        }
        return res;
    }
private:
    multiset<int> leastNumbers;
    vector<int> res;
};

int main()
{
    vector<int> input;
    vector<int> res;
    vector<int>::iterator it;
    // set<int> leastNumbers;
    // set<int>::iterator set_iter;
    int n, k, number;
    cin >> n >> k;
    for(int i = 0; i < n; ++i)
    {
        cin >> number;
        // leastNumbers.insert(number);
        input.push_back(number);
    }

    // for(set_iter = leastNumbers.begin(); set_iter != leastNumbers.end(); ++set_iter)
    // {
    //     cout << *set_iter << " ";
    // }
    // cout << endl;

    // set_iter = leastNumbers.end();
    // set_iter--;
    // cout << *set_iter << endl;
    Solution solution;
    res = solution.GetLeastNumbers_Solution(input, k);
    for(it = res.begin(); it != res.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}

// 题目描述
// 输入n个整数，找出其中最小的K个数。
// 例如输入4,5,1,6,2,7,3,8这8个数字，
// 则最小的4个数字是1,2,3,4,。

// Note:
// 1. k = 0
// 2. set_iter--; not set_iter = leastNumbers.end() - 1;
// 3. multiset not set to have the repeated numbers
// 4. leastNumbers.size() < k so that in "else" to add the last kth number in leastNumbers