class Solution {
public:
    vector<string> Permutation(string str) {
        string tmp;
        if(str.size() > 0) helper(str, tmp);
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
    
    void helper(string str, string &tmp)
    {
        if(str.size() == 0) 
        {
            res.push_back(tmp);
        }
        
        else
        {
            for(int i = 0; i < str.size(); ++i)
            {
                string str_tmp;
                str_tmp = swap(str, i);
                tmp = tmp + str_tmp[0];
                helper(str_tmp.substr(1, str_tmp.size() - 1), tmp);
                tmp = tmp.substr(0, tmp.size() - 1);
            }
        }
    }
    
    string swap(string str, int index)
    {
        char tmp = str[0];
        str[0] = str[index];
        str[index] = tmp;
        return str;
    }
    
private:
    vector<string> res;
};

// 输入一个字符串,按字典序打印出该字符串中字符的所有排列。
// 例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串
// abc,acb,bac,bca,cab和cba。

// 输入描述:
// 输入一个字符串,长度不超过9(可能有字符重复),字符只包括大小写字母。

// 运行时间：4ms

// 占用内存：492k