// class Solution {
// public:
//     bool isNumeric(char* string)
//     {
//         // exist e
//         bool dot_flag = false, e_flag = false;
//         int sig_pre_e = 0, sig_aft_e = 0;
//         if(string == NULL) return false;
//         while(*string != '\0')
//         {
//             if(*string == 'e' || *string == 'E')
//             {
//                 if(e_flag) return false; 
//                 e_flag = true;
//             }
//             else if(*string == '+' || *string == '-')
//             {
//                 // before e (e_flag = true) and sig_pre_e not set 
//                 if((e_flag == true && sig_aft_e == 0))
//                 {
//                     sig_aft_e = *string == '+' ? 1 : -1;
//                 }
//                 // before e and sig_pre_e not set
//                 else if(e_flag == false && sig_pre_e == 0)
//                 {
//                     sig_pre_e = *string == '+' ? 1 : -1;
//                 }
//                 else return false;
//             }
            
//             else if(*string == '.')
//             {
//                 if(dot_flag == false && e_flag == false) dot_flag = true;
//                 else return false;
//             }
//             else if(*string < '0' || *string > '9') return false;
//             ++string;
//         }
        
//         return true;
//     }
// };

// Does not consider : 12E - false

# include<bits/stdc++.h>
using namespace std;

void scanDigts(char **string)
{
    while(**string != '\0' && **string >= '0' && **string <= '9')
        ++(*string);
}

bool isExponential(char **string)
{
    if(**string != 'e' && **string != 'E')
        return false;
    ++(*string);

    if(**string == '+' || **string == '-') ++(*string);
    if(**string == '\0') return false;

    scanDigts(string);
    return (**string == '\0') ? true: false;
}

bool isNumeric(char *string)
{
    if(string == NULL) return false;
    if(*string == '+' || *string == '-')
        ++string;
    if(*string == '\0') return false;

    bool numeric = true;
    scanDigts(&string);

    if(*string != '\0')
    {
        if(*string == '.') 
        {
            ++string; scanDigts(&string);
            if(*string == 'e' || *string == 'E')
                numeric = isExponential(&string);
        }

        else if(*string == 'e' || *string == 'E')
            numeric = isExponential(&string);
        else
            numeric = false;
    }

    return numeric && *string == '\0';
}



int main()
{
    char *string = "123.45e+6";
    cout << isNumeric(string) << endl;
    return 0;
}

// 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
// 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
// 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。

// 运行时间：5ms
// 占用内存：596k