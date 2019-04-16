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
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root) dfs(root, expectNumber);
        return allRes;
    }
    void dfs(TreeNode *node, int target)
    {
        tmp.push_back(node->val);
        if(!node->left && !node->right)
        {
            if(target - node->val == 0)
                allRes.push_back(tmp);
        }
        else
        {
            if(node -> left) dfs(node->left, target - node->val);
            if(node -> right) dfs(node->right, target - node->val);
        }
        if(!tmp.empty())
            tmp.pop_back();
    }
private:
    vector<vector<int> >allRes;
    vector<int> tmp;
};

// 4. 二叉树中和为某一值的路径
// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)