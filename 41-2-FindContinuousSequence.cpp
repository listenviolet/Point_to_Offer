# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int> > res;
        vector<int> tmp;
        if(sum < 3) return res;

        int small = 1, big = 2;
        int tmp_sum = small + big;
        while(small <= sum / 2 && small < big)
        {
            if(tmp_sum == sum)
            {
                tmp = getTmp(small, big);
                res.push_back(tmp);

                ++big;
                tmp_sum += big;
            }
            else if(tmp_sum > sum)
            {
                tmp_sum -= small;
                ++small;
            }
            else
            {
                ++big;
                tmp_sum += big;
            }
        }
        return res;
    }

    vector<int> getTmp(int small, int big)
    {
        int i = small;
        vector<int> tmp;
        while(i <= big)
        {
            tmp.push_back(i);
            ++i;
        }
        return tmp;
    }
};

void display(vector<vector<int> > res)
{
    // vector<vector<int> >::iterator i;
    vector<int>::iterator it;
    for(int i = 0; i < res.size(); ++i)
    {
        for(it = res[i].begin(); it != res[i].end(); ++it)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int> > res;
    int n;
    Solution solution;
    while(cin >> n)
    {
        res = solution.FindContinuousSequence(n);
        display(res);
    }
    return 0;

    // vector<vector<int> > res;
    // int n;
    // int tmp_n;
    // int number;
    // cin >> n;
    // for(int i = 0; i < n; ++i)
    // {
    //     vector<int> tmp;
    //     cout << "tmp_n = ";
    //     cin >> tmp_n;
    //     for(int j = 0; j < tmp_n; ++j)
    //     {
    //         cin >> number;
    //         tmp.push_back(number);
    //     }
    //     res.push_back(tmp);
    //     cout << endl;
    // }

    // display(res);
    // return 0;
}

// ÌĿÃÊ
// СÃºÜ²»¶Êѧ,ÓһÌËÔ×Êѧ×ҵʱ,ҪÇ¼Æã9~16µĺÍ
// ËÂÉ¾Í´³öý¸Ê100¡£µ«ÊË²¢²»Â×Ó´Ë
// ËÔÏ¾¿¾¹Ó¶àÖlÐµÄýеĺÍª100(ÖÉ°üö¡£
// û¶à,Ë¾͵õ½Áһ×lÐÕÊºÍª100µÄò18,19,20,21,22¡£
// ÏÔ°ÑÊ⽻¸øã²»ÄҲºܿìÕ³öкÍªSµÄ¬ÐÕÊÐÁ? 
// Good Luck!
// Ê³öö/ Ê³öкÍªSµÄ¬ÐÕÊÐÁ¡£
// ÐÁÄ°´Õ´Ó¡Ö´ó³Ð£¬ÐÁ¼䰴Õ¿ªʼÊ×´Ó¡µ½´ó³Ð

// ÔÐʱ¼䣺4ms

// ռÓÄ´棺488k
