class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int len = array.size();
        vector<int> res;
        if(len == 0) return res;
        
        int *num1 = &array[0];
        int *num2 = &array[len - 1];
        
        while(num1 < num2)
        {
            if(*num1 + *num2 == sum) 
            {
                res.push_back(*num1);
                res.push_back(*num2);
                return res;
            }
            
            else if(*num1 + *num2 > sum)
            {
                --num2;
            }
            else ++num1;
        }
        
        return res;
    }
};

// 题目描述
// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，
// 如果有多对数字的和等于S，输出两个数的乘积最小的。

// 输出描述:
// 对应每个测试案例，输出两个数，小的先输出。

// 运行时间：3ms
// 占用内存：456k

// class Solution {
// public:
//     vector<int> FindNumbersWithSum(vector<int> array,int sum) {
//         int len = array.size();
//         vector<int> res;
//         if(len == 0) return res;
        
//         int i = 0, j = len - 1;
//         while(i < j)
//         {
//             if(array[i] + array[j] == sum) 
//             {
//                 res.push_back(array[i]);
//                 res.push_back(array[j]);
//                 return res;
//             }
            
//             else if(array[i] + array[j] > sum)
//             {
//                 --j;
//             }
//             else ++i;
//         }
        
//         return res;
//     }
// };