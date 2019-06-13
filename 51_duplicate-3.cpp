# include<bits/stdc++.h>
using namespace std;

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
        int index = 0;
        while(index < length)
        {            
            int tmp = numbers[index];
            if(tmp < 0 || tmp >= length) return false;
            if(tmp == index) {++index; continue;}
            
            int swap_tmp = numbers[tmp];
            if(swap_tmp = numbers[index]) 
            {
                *duplication = swap_tmp;
                return true;
            }
            numbers[tmp] = numbers[index];
            numbers[index] = swap_tmp;
        }
        return false;
    }  
};

int main()
{
	Solution solution;
	int numbers[] = {2,3,1,0,2,5,3};
	int length = 7;
	int duplication = -1;
	cout << solution.duplicate(numbers, length, &duplication) << " " << duplication << endl;
	cout << duplication << endl;
	return 0;
}

// Notcie:
// the condition when duplication occurrs is:
// swap_tmp = numbers[index]
// not swap_tmp < index 

// for example:
// 0 3 2 3 
//   |
// it will be in endless loop

