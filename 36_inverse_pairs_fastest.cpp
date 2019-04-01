static const auto io_sync_off = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}( );
class Solution {
public:
    static constexpr int P = 1000000007;
    vector<int>::iterator it;
    int InversePairs(vector<int>& data) {
        it = data.begin();
        if (data.empty())return 0;
        vector<int> dup(data);
        return merge_sort(data.begin(), data.end(), dup.begin());
    }
    //template<class RanIt>
    using RanIt = vector<int>::iterator;
    int merge_sort(const RanIt& begin1, const RanIt& end1, const RanIt& begin2) {
        int len = end1 - begin1;
        if (len < 2)return 0;
        int mid = ( len + 1 ) >> 1;
        auto m1 = begin1 + mid, m2 = begin2 + mid;
        auto i = m1, j = end1, k = begin2 + len;
        int ans = ( merge_sort(begin2, m2, begin1) + merge_sort(m2, k, m1) ) % P;
        for (--i, --j, --k; i >= begin1 && j >= m1; --k) {
            if (*i > *j) {
                *k = *i, --i;
                ( ans += j - m1 + 1 ) %= P;
            } else *k = *j, --j;
        }
        if (i >= begin1)copy(begin1, i + 1, begin2);
        else copy(m1, j + 1, begin2);
        return ans;
    }
  
};

// c++中我们通常采用std::cin来读入外部数据，
// 而C++中为了能向下兼容C，保证在代码中std :: cin和scanf一起出现时输出不出现错误，
// 所以C++用一个流缓冲区来同步C的标准流。
// 我们可以通过std :: ios :: sync_with_stdio函数可以解除这种同步，
// 让std :: cin不再经过缓冲区，从而达到增加数据读取速度的目的，来减少代码执行时间。
// 当然，关闭同步后，在程序中尽量不要使用c语言中的scanf，sscanf, getchar, fgets等函数，以免出现错误。
