# include <bits/stdc++.h>
using namespace std;
struct TreeNode
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode *pRoot, int &depth)
{

	if(pRoot == NULL) {depth = 0; return true;}
	int left = 0, right = 0;
	if(isBalanced(pRoot -> left, left) && isBalanced(pRoot -> right, right))
	{
		int diff = left - right;
		if(diff <= 1 && diff >= -1) 
		{
			depth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}

bool isBalanced(TreeNode *pRoot)
{
	int depth = 0;
	return isBalanced(pRoot, depth);
}

int main()
{
	TreeNode *node1 = new TreeNode(1);
	TreeNode *node2 = new TreeNode(2);
	TreeNode *node3 = new TreeNode(3);
	TreeNode *node4 = new TreeNode(4);

	// true
	node1 -> left = node2;
	node1 -> right = node3;
	node3 -> right = node4;

	// false
	// node1 -> right = node2;
	// node2 -> right = node3;
	// node3 -> right = node4;

	cout << isBalanced(node1) << endl;
	return 0;
}

// 输入一棵二叉树，判断该二叉树是否是平衡二叉树。
// use post order instead of pre order to avoid visiting the same node multi times 
// 运行时间：4ms

// 占用内存：476k