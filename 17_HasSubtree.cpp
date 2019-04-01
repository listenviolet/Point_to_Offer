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
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2 == NULL) return false;
        if(pRoot1 == NULL && pRoot2) return false;
        bool flag = false;
        if(pRoot1->val == pRoot2->val)
        {
            flag = visit(pRoot1, pRoot2);
        }
        if(!flag)
        {
            flag = HasSubtree(pRoot1->left, pRoot2);
            if(!flag)
            {
                flag = HasSubtree(pRoot1->right, pRoot2);
            }
        }
        return flag;
    }
    
    bool visit(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        //if(pRoot1 == NULL && pRoot2 == NULL) return true;
        if(pRoot1 == NULL && pRoot2) return false;
        if(pRoot2 == NULL) return true;
        if(pRoot1->val == pRoot2->val)
        {
            return visit(pRoot1->left, pRoot2->left) && visit(pRoot1->right, pRoot2->right);
        }
        else return false;
    }
};