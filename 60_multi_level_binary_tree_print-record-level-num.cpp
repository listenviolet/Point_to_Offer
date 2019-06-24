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
        queue<TreeNode*> nodes;
        nodes.push(pRoot);
        int nextLevel = 0;
        int toBePrinted = 1;
        while(!nodes.empty())
        {
            TreeNode *pNode = nodes.front();
            level.push_back(pNode -> val);
            
            if(pNode -> left != NULL) 
            {
                nodes.push(pNode -> left);
                ++nextLevel;
            }
            if(pNode -> right != NULL)
            {
                nodes.push(pNode -> right);
                ++nextLevel;
            }
            nodes.pop();
            --toBePrinted;
            if(toBePrinted == 0)
            {
                res.push_back(level);
                level.clear();
                toBePrinted = nextLevel;
                nextLevel = 0;
            }
        }
        return res;
    }
private:
    vector<int> level;
    vector<vector<int> > res;
};

// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
// 运行时间：5ms
// 占用内存：468k