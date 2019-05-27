# include<bits/stdc++.h>
# include<hash_map>
using namespace std;
using namespace __gnu_cxx;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        hash_map<char, int> dict;
        for(int i = 0; i < str.size(); ++i)
        {
            if(dict.find(str[i]) != dict.end()) dict[str[i]]++;
            else dict[str[i]] = 1;
        }
        
        char c;
        for(int i = 0; i < str.size(); ++i)
        {
            if(dict[str[i]] == 1) 
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    string str;
    while(cin >> str)
    {
        cout << solution.FirstNotRepeatingChar(str) << endl;
        // solution.FirstNotRepeatingChar(str);
    }
    
    return 0;
}

// 在一个字符串(0<=字符串长度<=10000，全部由字母组成)中
// 找到第一个只出现一次的字符,并返回它的位置, 
// 如果没有则返回 -1（需要区分大小写）.

// 运行时间：4ms

// 占用内存：460k

// class Solution {
// public:
//     int FirstNotRepeatingChar(string str) {
//         if(str.size() == 0) return -1;
//         const int tablesize = 256;
//         unsigned int hashTable[tablesize];
//         for(unsigned int i = 0; i < tablesize; ++i)
//             hashTable[i] = 0;
        
//         for(int i = 0; i < str.size(); ++i)
//         {
//             hashTable[str[i]]++;
//         }
        
//         for(int i = 0; i < str.size(); ++i)
//         {
//             if(hashTable[str[i]] == 1) return i;
//         }
        
//         return -1;
//     }
// };