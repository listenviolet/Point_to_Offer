class Solution {
public:
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
        bool flag = false;
        for(int start = 0; start < rows * cols; ++start)
        {
            if(matrix[start] == *str)
            {
                flag = dfs(matrix, rows, cols, str, start);
                if(flag) return true;
            } 
        }
        return flag;
    }
    
    bool dfs(char *matrix, int rows, int cols, char *str, int cur)
    {
        if(*str == '\0') return true;
        if(cur < 0 || cur >= rows * cols) return false;
        if(*str != matrix[cur]) return false;
        char temp = matrix[cur];
        matrix[cur] = '*';
        bool flag = false;
        flag = dfs(matrix, rows, cols, str+1, cur - cols) || dfs(matrix, rows, cols, str + 1, cur + cols) || dfs(matrix, rows, cols, str + 1, cur - 1) || dfs(matrix, rows, cols, str + 1, cur + 1);
        if(flag == false) matrix[cur] = temp;
        return flag;
    } 
};

// 运行时间：3ms
// 占用内存：468k

// 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。
// 路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。
// 如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 
// 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，
// 但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。