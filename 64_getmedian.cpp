class Solution {
public:
    void Insert(int num)
    {
        // even
        if(((min.size() + max.size()) & 1) == 0)
        {
            if(max.size() > 0 && num < max[0])
            {
                max.push_back(num);
                push_heap(max.begin(), max.end(), less<double>());
                num = max[0];
                pop_heap(max.begin(), max.end(), less<double>());
                max.pop_back();
            }
            
            min.push_back(num);
            push_heap(min.begin(), min.end(), greater<double>());
        }
        // odd
        else
        {
            if(min.size() > 0 && num > min[0])
            {
                min.push_back(num);
                push_heap(min.begin(), min.end(), greater<double>());
                num = min[0];
                pop_heap(min.begin(), min.end(), greater<double>());
                min.pop_back();
            }
            max.push_back(num);
            push_heap(max.begin(), max.end(), less<double>());
        }
    }

    double GetMedian()
    { 
        int size = min.size() + max.size();
        if(size == 0)
            return 0;
        double median = 0;
        if((size & 1) == 0) median = (min[0] + max[0]) / 2;
        else if((size & 1) == 1) median = min[0];
        return median;
    }
private:
    vector<double> min;
    vector<double> max;
};
// 题目描述
// 如何得到一个数据流中的中位数？
// 如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。
// 如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
// 我们使用Insert()方法读取数据流，使用GetMedian()方法获取当前读取数据的中位数。

// 运行时间：3ms
// 占用内存：488k