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
        vector<int> vec;
        if(root == NULL) return vec;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode *cur = nullptr;
        while(!q.empty())
        {
            cur = q.front();
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right);
            vec.push_back(cur -> val);
            q.pop();
        }
        return vec;
    }
};
// 从上往下打印出二叉树的每个节点，同层节点从左至右打印。

// 运行时间：4ms

// 占用内存：480k