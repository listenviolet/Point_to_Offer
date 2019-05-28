# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        vector<int> copy;
        vector<int>::iterator it;
        for(it = data.begin(); it != data.end(); ++it)
        {
            copy.push_back(*it);
        }
        
        sort(copy.begin(), copy.end());
        cout << "copy" << endl;
        for(it = copy.begin(); it != copy.end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;

        int cnt = 0;
        for(int i = 0; i < data.size(); ++i)
        {
            int indexOfCopy = find(copy, data[i], 0, copy.size());
            cout << "data = " << data[i] << " in data index = " << i << " in copy index = " << indexOfCopy << endl;
            if(indexOfCopy > i) 
            {
                cnt += (indexOfCopy - i);
                cnt %= 1000000007;
            }
            else continue;
        }
        
        return cnt;
    }
    
    int find(vector<int> copy, int number, int l, int r)
    {
        int mid = (l + r) / 2;
        if(copy[mid] == number) return mid;
        if(copy[mid] < number) return find(copy, number, mid + 1, r);
        else return find(copy, number, l, mid);
    }
};

int main()
{
    int n, number;
    
    while(cin >> n)
    {
        vector<int> data;
        for(int i = 0; i < n; ++i)
        {
            cin >> number;
            data.push_back(number);
        }
        
        int result;
        Solution solution;
        result = solution.InversePairs(data);
        cout << result << endl;
    }
    return 0;
}