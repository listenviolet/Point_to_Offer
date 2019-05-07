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
        // if(root == NULL) return allRes;
        if(root != NULL ) dfs(root, expectNumber, tmp);
        return allRes;
    }
    
    void dfs(TreeNode *root, int expectNumber, vector<int> tmp)
    {
        tmp.push_back(root -> val);
        if(root -> left == NULL && root -> right == NULL && root -> val == expectNumber) allRes.push_back(tmp);
        else if(expectNumber > root -> val)
        {
            if(root -> left) dfs(root -> left, expectNumber - root -> val, tmp);
            if(root -> right) dfs(root -> right, expectNumber - root -> val, tmp);
        }
        if(!tmp.empty()) tmp.pop_back();
    }
    
private:
    vector<vector<int> > allRes;
    vector<int> tmp;
};

// 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
// 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
// (注意: 在返回值的list中，数组长度大的数组靠前)

// 运行时间：3ms
// 占用内存：608k