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
    	convert_subtree(pRootOfTree, &pLastNodeInList);

    	TreeNode *head = pLastNodeInList;
    	while(head != NULL && head -> left != NULL)
    	{
    		head = head -> left;
    	}
    	return head;
    }

    void convert_subtree(TreeNode *pNode, TreeNode **pLastNodeInList)
    {
    	if(pNode == NULL) return;
    	if(pNode -> left)
    	{
    		convert_subtree(pNode -> left, pLastNodeInList);
    	}
    	pNode -> left = *pLastNodeInList;
    	if(*pLastNodeInList != NULL)
    		(*pLastNodeInList) -> right = pNode;
    	
    	*pLastNodeInList = pNode;
    	if(pNode -> right != NULL)
    	{
    		convert_subtree(pNode -> right, pLastNodeInList);
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

// Description:
// 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。
// 要求不能创建任何新的结点，只能调整树中结点指针的指向。

// use in order to traverse the tree
// when doing the node -> max_of_left_subtree
// the left_subtree already sorted in the bidirect linked list

// pLastNodeInList record the last node of the linked list
// so the next node be connected after pLastNodeInList 
// is the smallest node in the other part of the tree 

// which is always the max of the left subtree
// so only do the bidirect link after the convert(node -> left)
// not after convert(node -> right)

// Notice:
// in void convert_subtree(TreeNode *pNode, TreeNode **pLastNodeInList)
// uses the pointer point to a pointer
// in order to change the pointer's pointing
// ex. *pLastNodeInList = pNode;

// when call this function, be attention to use '&'
// ex. convert_subtree(pRootOfTree, &pLastNodeInList);