/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        if(pRoot == NULL) return res;
        stack<TreeNode *> level[2];
        int current = 0;
        int next = 1;
        level[current].push(pRoot);
        while(!level[0].empty() || !level[1].empty())
        {
            TreeNode *pNode = level[current].top();
            level[current].pop();
            level_val.push_back(pNode -> val);
            if(current == 0) 
            {
                if(pNode -> left != NULL) level[next].push(pNode -> left);
                if(pNode -> right != NULL) level[next].push(pNode -> right);
            }
            if(current == 1)
            {
                if(pNode -> right != NULL) level[next].push(pNode -> right);
                if(pNode -> left != NULL) level[next].push(pNode -> left);
            }
            
            if(level[current].empty())
            {
                res.push_back(level_val);
                level_val.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return res;
    }
private:
    vector<int> level_val;
    vector<vector<int> > res;
};


// 运行时间：5ms
// 占用内存：484k

// 题目描述
// 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
// 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。

// 0
// 1
// 2
// ...

// if current is even: save the children in a stack in left to right order 
// if current is odd: save the children in a stack in right to left oder 
// use 1 - current; 1 - next to change the odd/even when current level stack is empty