class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        if(matrix.empty()) return res;
        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        
        while(r < (min(m, n) + 1) / 2 )
        {
            int i = r, j = r;
            for(j = r; j <= n - r - 1; ++j)
            {
                res.push_back(matrix[r][j]);
            }
            
            for(i = r + 1; i <= m - r  - 1; ++i)
            {
                res.push_back(matrix[i][n - r - 1]);
            }
            
            
            if(n - r - 2 >= r && m - r - 1 > r)
            {
                for(j = n - r - 2; j >= r; --j)
                {
                    res.push_back(matrix[m - r - 1][j]);
                }

                for(i = m - r - 2; i >= r + 1; --i)
                {
                    res.push_back(matrix[i][r]);
                }
            }
            
            ++r;
        }
        
        return res;
    }
};

// 输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，
// 例如，如果输入如下4 X 4矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 则依次打印出数字1,2,3,4,8,12,16,15,14,13,9,5,6,7,11,10.

// 运行时间：4ms

// 占用内存：624k
// alg:
// xxxxxx
// o    o
// o    o
// xxxxxo