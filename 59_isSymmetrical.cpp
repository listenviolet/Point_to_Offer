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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot == NULL) return true;
        return helper(pRoot -> right, pRoot -> left);
    }
    
    bool helper(TreeNode *right, TreeNode *left)
    {
        if(right == NULL && left == NULL) return true;
        else if(right == NULL || left == NULL) return false;
        else if(right -> val != left -> val) return false;
        else
        {
            return helper(right -> right, left -> left) && helper(right -> left, left -> right);
        }
    }
};

// 运行时间：4ms
// 占用内存：468k

// 请实现一个函数，用来判断一颗二叉树是不是对称的。
// 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。