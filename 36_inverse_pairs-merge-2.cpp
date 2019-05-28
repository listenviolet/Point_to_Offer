# include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        if(data.size() == 0) return 0;
        vector<int> copy(data);
        
        
        int cnt = mergeInverse(data, copy, 0, data.size() - 1);
        return cnt;
    }
     
    int mergeInverse(vector<int> &data, vector<int> &copy, int start, int end)
    {
        if(start == end) 
        { 
            copy[start] = data[start];
            return 0;
        }


        vector<int>::iterator it;

         
        int half_len = (end - start) / 2;
        int left_cnt = mergeInverse(copy, data, start, start + half_len) % 1000000007;
        int right_cnt = mergeInverse(copy, data, start + half_len + 1, end) % 1000000007;
         
        int i = start + half_len;
        int j = end;
        int copy_index = end;
         
        int cnt = 0;
        while(i >= start && j >= start + half_len + 1)
        {
            cout << "data[i] = " << data[i] << " data[j] =" << data[j] << endl;
            if(data[i] > data[j])
            {
                copy[copy_index--] = data[i--];
                cnt += (j - start - half_len);
                cnt %= 1000000007;
            }
             
            else copy[copy_index--] = data[j--];
        }
         
        for(; i >= start; --i)
        {
            copy[copy_index--] = data[i];
        }
             
        for(; j >= start + half_len + 1; --j)
        {
            copy[copy_index--] = data[j];
        }

        for(it = copy.begin(); it != copy.end(); ++it)
        {
            cout << *it << " ";
        }

        cout << endl;

        cout << "start = " << start << " end = " << end << endl;
        cout << "========================" << endl;
             
        return (left_cnt + right_cnt + cnt) % 1000000007;
    }
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

// 运行时间：70ms

// 占用内存：5444k
// Notice:
// 1. use vecotr<int> & otherwise the vector changed in the sub mergeInverse 
// will not be updated in the main mergeInverse
// 2. if(start == end) is the end of recursive condition, use return 0 to return
// 3. cnt += (j - start - half_len); cnt %= 1000000007;
//    not cnt += (j - start - half_len) % 1000000007
//    because the total sum in cnt may exceed 1000000007

// 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
// 输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

// 输入描述:
// 题目保证输入的数组中没有的相同的数字

// 数据范围：

//     对于%50的数据,size<=10^4

//     对于%75的数据,size<=10^5

//     对于%100的数据,size<=2*10^5

// 示例1
// 输入
// 复制
// 1,2,3,4,5,6,7,0
// 输出
// 复制
// 7