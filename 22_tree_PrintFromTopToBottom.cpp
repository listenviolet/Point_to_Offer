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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        queue<TreeNode* > q;
        vector<int> tree;
        if(root == NULL) return tree;
        q.push(root);
        TreeNode *u = new TreeNode(-1);
        while(!q.empty())
        {
            u = q.front();
            q.pop();
            tree.push_back(u->val);
            if(u->left != NULL) q.push(u->left);
            if(u -> right != NULL) q.push(u -> right);
        }
        return tree;
    }
};

// Notice:
// if(root == NULL) return tree;
// otherwise NUll will be pushed to queue