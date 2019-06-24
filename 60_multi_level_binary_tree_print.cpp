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
        queue<TreeNode*> que[2];
        int current = 0;
        int next = 1;
        que[current].push(pRoot);
        while(!que[0].empty() || !que[1].empty())
        {
            TreeNode *pNode = que[current].front();
            que[current].pop();
            level.push_back(pNode -> val);
            
            if(pNode -> left != NULL) que[next].push(pNode -> left);
            if(pNode -> right != NULL) que[next].push(pNode -> right);
            if(que[current].empty())
            {
                res.push_back(level);
                level.clear();
                current = 1 - current;
                next = 1 - next;
            }
        }
        return res;
    }
private:
    vector<int> level;
    vector<vector<int> > res;
};

// 运行时间：4ms
// 占用内存：488k

// 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
// as z shape
// use current and next to read current level nodes and save for the next level.
// use queue to record