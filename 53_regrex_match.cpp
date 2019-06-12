class Solution {
public:
    bool match(char* str, char* pattern)
    {
        if(str == NULL || pattern == NULL) return false;
        return matchCore(str, pattern);
    }
    
    bool matchCore(char *str, char *pattern)
    {
        if(*str == '\0' && *pattern == '\0') return true;
        if(*str != '\0' && *pattern == '\0') return false;
        
        if(*(pattern + 1) == '*')
        {
            // match one 
            if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            {   // match one and move on || repeat one || repeat 0
                return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
            }
            // not match
            else 
                return matchCore(str, pattern + 2);
        }
        
        if(*str == *pattern || (*pattern == '.' && *str != '\0'))
            return matchCore(str + 1, pattern + 1);
        return false;
    }
};

// 题目描述
// 请实现一个函数用来匹配包括'.'和'*'的正则表达式。
// 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
// 在本题中，匹配是指字符串的所有字符匹配整个模式。
// 例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配

// two cases:
// 1. the second is *
// 1) the first one match
//    ch == ch || ch == '.' 
// 2) the first one does not match 

// 2. the second is not *
// 1) the first one match 

// 运行时间：5ms
// 占用内存：476k

// Notice: 
// the '.' can match any char except '\0'