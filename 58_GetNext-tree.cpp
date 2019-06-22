/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        // pNode is NULL or pNode is root
        if(pNode == NULL) return NULL;
        // pNode has right child
        if(pNode -> right != NULL)
        {
            pNode = pNode -> right;
            while(pNode -> left != NULL)
            {
                pNode = pNode -> left;
            }
            return pNode;
        }
        else
        {
            while(pNode -> next != NULL && pNode -> next -> right == pNode)
            {
                pNode = pNode -> next;
            }
            if(pNode -> next == NULL) return NULL;
            else return pNode -> next;
            // can be replaced: return pNode -> next 
            // do not need if else
        }
    }
};

// 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。
// 注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。

// 运行时间：4ms
// 占用内存：604k

// 1. pNode has right sub tree: find the most left one in the right sub tree;
// 2. pNode doesn't has right sub tree: 
// find the first node which is the right child of its parent, return its parent node
// else pNode = pNode -> next