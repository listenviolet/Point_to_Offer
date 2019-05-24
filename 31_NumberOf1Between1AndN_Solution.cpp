class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        if(n < 0) return 0;
        int i = 0, high = n, cnt = 0;
        int tmp = 0, low = 0, cur = 0;
        while(high != 0)
        {
            high = n / pow(10, i + 1);
            tmp = n / pow(10, i);
            cur = tmp % 10;
            low = n - tmp * pow(10, i);
             
            if(cur < 1) cnt += high * pow(10, i);
            if(cur > 1) cnt += (high + 1) * pow(10, i);
            if(cur == 1)
            {
                cnt += high * pow(10, i);
                cnt += (low + 1);
            }
            ++i;
        }
         
        return cnt;
    }
};

// 求出1~13的整数中1出现的次数,并算出100~1300的整数中1出现的次数？
// 为此他特别数了一下1~13中包含1的数字有1、10、11、12、13因此共出现6次,
// 但是对于后面问题他就没辙了。
// ACMer希望你们帮帮他,并把问题更加普遍化,
// 可以很快的求出任意非负整数区间中1出现的次数（从1 到 n 中1出现的次数）。
