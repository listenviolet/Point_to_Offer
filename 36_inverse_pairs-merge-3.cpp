# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        vector<int> copy(data);
        int cnt = merge(data, copy, 0, data.size() - 1);
        return cnt;
    }
    
    int merge(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if(start == end)
        {
            copy[start] = data[start];
            return 0;
        }
        int len = (end - start) >> 1;
        int left_cnt = merge(copy, data, start, start + len);
        int right_cnt = merge(copy, data, start + len + 1, end);
        
        int i = start + len;
        int j = end;
        int copy_index = end;
        int cnt = 0;
        while(i >= start && j >= start + len + 1)
        {
            if(data[i] > data[j]) 
            {
                copy[copy_index--] = data[i--];
                cnt += j - start - len;
                cnt %= P;
            }
            
            else copy[copy_index--] = data[j--];
        }
        
        for(; i >= start; --i)
        {
            copy[copy_index--] = data[i];
        }
        for(; j >= start + len + 1; --j)
        {
            copy[copy_index--] = data[j];
        }
        
        return (left_cnt + right_cnt + cnt) % P;
    }
const int P = 1000000007;
};

int main()
{
    int n, number;
    // int a[] = {627126,415347,850134,371085,279048,705820,453064};
    // int a[] = {627126,415347,850134,371085,279048,705820};
    int a[] = {3, 2, 1};
    vector<int> data(a, a + sizeof(a) / sizeof(a[0]));
    // for(int i = 0; i < n; ++i)
    // {
    //     cin >> number;
    //     data.push_back(number);
    // }
    
    int result;
    Solution solution;
    result = solution.InversePairs(data);
    cout << result << endl;
    
    return 0;
}
