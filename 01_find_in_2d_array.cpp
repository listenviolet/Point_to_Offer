class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        if(array.empty()) return false;
        return find(target, array, 0, array[0].size() - 1);
    }
    
    bool find(int target, vector<vector<int> > array, int x, int y)
    {
        if(x >= array.size() || y < 0) return false;
        if(target == array[x][y]) return true;
        if(target > array[x][y]) 
        {
            return find(target, array, x + 1, y);
        }
        else
        {
            return find(target, array, x, y - 1);
        }
    }
};


// 1. 二维数组中的查找
// 在一个二维数组中（每个一维数组的长度相同），
// 每一行都按照从左到右递增的顺序排序，
// 每一列都按照从上到下递增的顺序排序。
// 请完成一个函数，输入这样的一个二维数组和一个整数，
// 判断数组中是否含有该整数。

// 运行时间：16ms

// 占用内存：2984k