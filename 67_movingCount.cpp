# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        bool *visited = new bool[rows * cols];
        for(int i = 0; i < rows * cols; ++i)
        {
            visited[i] = false;
        }

        int total = 0;
        int row = 0, col = 0;
        dfs(visited, threshold, rows, cols, row, col, total);
        return total;
    }
    bool digitSum(int threshold, int row, int col)
    {
        int sum = 0;
        while(row > 0)
        {
            sum += row % 10;
            row /= 10;
        }
        while(col > 0)
        {
            sum += col % 10;
            col /= 10;
        }
        
        if(sum <= threshold) return true;
        return false;
    }
    void dfs(bool *visited, int threshold, int rows, int cols, int row, int col, int &total)
    {
        if(row >= rows || col >= cols || visited[row * cols + col] == true || digitSum(threshold, row, col) == false) return;
        total += 1;
        visited[row * cols + col] = true;
        dfs(visited, threshold, rows, cols, row + 1, col, total);
        dfs(visited, threshold, rows, cols, row, col + 1, total);
    }
    
};

int main()
{
    Solution solution;
    int threshold = 18, rows = 40, cols =  40;
    // cout << solution.digitSum(threshold, row, col) << endl;
    cout << solution.movingCount(threshold, rows, cols) << endl;
    return 0;
}

// 运行时间：4ms
// 占用内存：588k

// 地上有一个m行和n列的方格。一个机器人从坐标0,0的格子开始移动，
// 每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 
// 例如，当k为18时，机器人能够进入方格（35,37），因为3+5+3+7 = 18。
// 但是，它不能进入方格（35,38），因为3+5+3+8 = 19。请问该机器人能够达到多少个格子？