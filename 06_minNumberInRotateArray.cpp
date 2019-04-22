class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty()) return 0;
        int index1 = 0;
        int index2 = rotateArray.size() - 1;
        int mid = index1;
        while(rotateArray[index2] <= rotateArray[index1])
        {
            if(index2 == index1 + 1)
            {
                mid = index2;
                break;
            }
            
            mid = (index1 + index2) / 2;
            
            if(rotateArray[index1] == rotateArray[index2] && rotateArray[mid] == rotateArray[index1])
            {
                return *min_element(rotateArray.begin(), rotateArray.end());
            }
            
            if(rotateArray[index1] <= rotateArray[mid])
            {
                index1 = mid;
            }
            
            else if(rotateArray[index2] >= rotateArray[mid])
            {
                index2 = mid;
            }
        }
        
        return rotateArray[mid];
    }
};

6. 旋转数组的最小数字
把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。 输入一个非减排序的数组的一个旋转，输出旋转数组的最小元素。 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。 NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。

binary-search

init: mid = index1 
in case the vector is already sorted. 

attention: [mid] = [index1] = [mid2]
have to loop over the vector

运行时间：22ms

占用内存：612k