// #include <iostream>
// #include <cstdio>
// #include <vector>
# include <bits/stdc++.h>
using namespace std;
int list[maxn];
int InversePairs(vector<int> data);
int InversePairsCore(vector<int> data, vector<int> &copy, int start, int end);

int InversePairs(vector<int> data) {
    if (data.empty()) return 0;
    int length = data.size();
    vector<int> copy = data;
    // for(int i = 0; i < length; ++i)
    // {
    //     copy[i] = data[i];
    // }
    
    int count = InversePairsCore(data, copy, 0, length - 1) ;
    vector<int>().swap(copy);
    if(count > 1000000007) return count % 1000000007;
    return count;
}

int InversePairsCore(vector<int> data, vector<int> &copy, int start, int end)
{
    if (start == end)
    {
        copy[start] = data[start];
        return 0;
    }
    
    int length = (end - start) / 2;
    int left = InversePairsCore(copy, data, start, start + length);
    int right = InversePairsCore(copy, data, start + length + 1, end);
    
    int i = start + length;
    int j = end;
    int indexcopy = end;
    int count = 0;
    
    while (i >= start && j >= start + length + 1)
    {
        if (data[i] > data[j])
        {
            copy[indexcopy--] = data[i--];
            count += j - (start + length);
        }
        else
        {
            copy[indexcopy--] = data[j--];
        }
    }
    
    for(; i >= start; --i)
    {
        copy[indexcopy--] = data[i];
    }
    
    for(;j >= start + length + 1; --j)
    {
        copy[indexcopy--] = data[j];
    }
    
    return left + right + count;
}

int main()
{
    // int list[] = {364,637,341,406,747,995,234,971,571,219,993,407,416,366,315,301,601,650,418,355,460,505,360,965,516,648,727,667,465,849,455,181,486,149,588,233,144,174,557,67,746,550,474,162,268,142,463,221,882,576,604,739,288,569,256,936,275,401,497,82,935,983,583,523,697,478,147,795,380,973,958,115,773,870,259,655,446,863,735,784,3,671,433,630,425,930,64,266,235,187,284,665,874,80,45,848,38,811,267,575};
    // int list[] = {1,2,3,4,5,6,7,0};  

    string s;
    cin >> s;


    int length = sizeof(list) / sizeof(list[0]);
    printf("%d\n", length);

    vector<int> data(length);
    for(int i = 0; i < length; ++i)
    {
        data[i] = list[i];
    }


    int count = InversePairs(data);
    printf("%d\n", count);
    return 0;
}
