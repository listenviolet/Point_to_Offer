# include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        TreeNode *pLastNodeInList = nullptr;
        convertNode(pRootOfTree, &pLastNodeInList);

        TreeNode *pHeadOfList = pLastNodeInList;
        while(pHeadOfList != NULL && pHeadOfList -> left != NULL)
        {
            pHeadOfList = pHeadOfList -> left;
        }
        return pHeadOfList;
    }
    
    void convertNode(TreeNode *pNode, TreeNode **pLastNodeInList)
    {
        if(pNode == NULL)
        {
            return;
        }
        TreeNode *pCurrent = pNode;
        if(pNode -> left != NULL)
        {
            convertNode(pNode -> left, pLastNodeInList);
        }

        pCurrent -> left = *pLastNodeInList;
        if(*pLastNodeInList != NULL)
            (*pLastNodeInList) -> right = pCurrent;

        *pLastNodeInList = pCurrent;
        if(pNode -> right != NULL)
        {
            convertNode(pCurrent -> right, pLastNodeInList);
        }
    }

};

int main()
{
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);

    node3->left = node1;
    node1->right = node2;
    node3->right = node5;
    node5->left = node4;
    node5->right = node6;

    Solution solution;
    TreeNode *head = nullptr;
    head = solution.Convert(node3);
    while(head)
    {
        cout << head -> val << "->" ;
        head = head -> right; 
    }
    return 0;
}