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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL) return pRootOfTree;
        return inOrder(pRootOfTree);
    }
    
    TreeNode *inOrder(TreeNode *root)
    {
        TreeNode *leftTree = nullptr;
        TreeNode *rightTree= nullptr;
        if(root -> left != NULL) leftTree = inOrder(root -> left);
        TreeNode *lastOfLeft = lastNode(leftTree);
        root -> left = lastOfLeft;
        if(leftTree != NULL) lastOfLeft -> right = root;
        
        if(root -> right != NULL) rightTree = inOrder(root -> right);
        root -> right = rightTree;
        if(rightTree != NULL)
        {
            rightTree -> left = root;
        }
        
        if(leftTree != NULL) return leftTree;
        else return root;
    }
    
    TreeNode *lastNode(TreeNode *pHead)
    {
        if(pHead == NULL) return pHead;
        TreeNode *p1 = pHead;
        while(p1 -> right != NULL)
        {
            p1 = p1 -> right;
        }
        return p1;
    }
};

// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。
// 运行时间：3ms
// 占用内存：488k
