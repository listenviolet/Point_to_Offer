class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        string str;
        if(numbers.size() == 0) return str;
        
        sort(numbers.begin(), numbers.end(), cmp);
        vector<int>::iterator it;
        for(it = numbers.begin(); it != numbers.end(); ++it)
        {
            str += to_string(*it);
        }
        return str;
    }
    
    static bool cmp(int a, int b)
    {
        string str_ab, str_ba, str_a, str_b;
        str_a = to_string(a);
        str_b = to_string(b);
        str_ab = str_a + str_b;
        str_ba = str_b + str_a;
        
        for(int i = 0; i < str_ab.size(); ++i)
        {
            if(str_ab[i] < str_ba[i]) return true;
            else if(str_ab[i] > str_ba[i]) return false;
        }
        
        return true;
    }
};

// 题目描述
// 输入一个正整数数组，把数组里所有数字拼接起来排成一个数，
// 打印能拼接出的所有数字中最小的一个。例如输入数组{3，32，321}，
// 则打印出这三个数字能排成的最小数字为321323。

// 运行时间：5ms

// 占用内存：376k