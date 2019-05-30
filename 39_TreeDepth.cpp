/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        // if(pRoot -> left == NULL && pRoot -> right == NULL) return 1;
        int left = 0, right = 0;
        if(pRoot -> left != NULL) left = TreeDepth(pRoot -> left);
        if(pRoot -> right != NULL) right = TreeDepth(pRoot -> right);
        return max(left, right) + 1;
    }
};

// 输入一棵二叉树，求该树的深度。
// 从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，
// 最长路径的长度为树的深度。

// 运行时间：3ms

// 占用内存：600k