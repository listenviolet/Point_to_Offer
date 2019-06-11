# include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     // Parameters:
//     //        numbers:     an array of integers
//     //        length:      the length of array numbers
//     //        duplication: (Output) the duplicated number in the array number
//     // Return value:       true if the input is valid, and there are some duplications in the array number
//     //                     otherwise false
//     bool duplicate(int numbers[], int length, int* duplication) {
//         if(length == 0) return false;
//         int *dict = new int[length];
//         memset(dict, 0, sizeof(dict));
//         int tmp;
//         for(int i = 0; i < length; ++i)
//         {
//             tmp = numbers[i];
//             if(tmp < 0 || tmp >= length) return false;
//             if(dict[tmp] == 1) {*duplication = tmp; return true;}
//             if(dict[tmp] == 0) dict[tmp] += 1;
//         }
//         return false;
//     }
// };

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers == NULL || length <= 0) return false;
        int *dict = new int[length];
        memset(dict, 0, sizeof(dict));
        int tmp;
        for(int i = 0; i < length; ++i)
        {
            tmp = numbers[i];
            if(tmp < 0 || tmp >= length) return false;
            dict[tmp] += 1;
        }
        
        for(int i = 0; i < length; ++i)
        {
            if(dict[numbers[i]] > 1) {*duplication = numbers[i]; return true;}
        }
        return true;
    }
};

int main()
{
    Solution solution;
    // int numbers[] = {2,3,1,0,2,5,3};
    int numbers[] = {2, 1, 3, 1, 4};
    int length = 5;
    int duplication;
    cout << solution.duplicate(numbers, length, &duplication) << endl;
    cout << "duplication = " << duplication << endl;
    return 0;
}

// Error
// This method will find the first number in its second time number: 
// {2, 1, 3, 1, 4, 2}
// it should return duplication = 2 
// but it returns duplication = 1
// it is because dict[1] will get 2 first

// Correct:

// Error again~~~