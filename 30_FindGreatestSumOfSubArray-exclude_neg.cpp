class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.size() == 0)
        {
            invalidInput = true;
            return 0;
        }
        int Max = 0x80000000;
        int CurSum = 0;
        for(int i = 0; i < array.size(); ++i)
        {
            if(CurSum < 0) CurSum = array[i];
            else CurSum += array[i];
            if(CurSum > Max) Max = CurSum;
        }
        
        return Max;
    }
private:
    bool invalidInput = false;
};

// 连续子数组的最大和

// HZ测试组开完会后,他又发话了:在古老的一维模式识别中,常常需要计算连续子向量的最大和,
// 当向量全为正数的时候,问题很好解决。
// 但是,如果向量中包含负数,是否应该包含某个负数,并期望旁边的正数会弥补它呢？
// 例如:{6,-3,-2,7,-15,1,2,2},连续子向量的最大和为8(从第0个开始,到第3个为止)。
// 给一个数组，返回它的最大连续子序列的和.(子向量的长度至少是1)

// 运行时间：4ms

// 占用内存：580k