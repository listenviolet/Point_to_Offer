class Solution {
public:
    int getMax(int st, int end, vector<int> num)
    {
        int xmax = INT_MIN;
        for(int i = st; i <= end; ++i)
        {
            if(xmax < num[i]) xmax = num[i];
        }
        return xmax;
    }
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        // if(size < num.size()) return max_list;
        if(size < 1 || size > num.size()) return max_list;
        int x_max = getMax(0, size - 1, num);
        max_list.push_back(x_max);
        for(int i = size; i < num.size(); ++i)
        {
            int st = num[i - size];
            if(st < x_max) 
            {
                x_max = max(x_max, num[i]);
            }
            else if(st == x_max) x_max = getMax(i - size + 1, i, num);
            max_list.push_back(x_max);
        }
        return max_list;
    }
private:
    vector<int> max_list;
};

// 运行时间：3ms
// 占用内存：480k

// 给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
// 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
// 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 
// 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： 
// {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， 
// {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
// {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。