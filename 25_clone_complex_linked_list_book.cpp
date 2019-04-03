# include <bits/stdc++.h>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    void CloneNodes(RandomListNode *pHead)
    {
    	RandomListNode *pNode = pHead;
    	while(pNode != NULL)
    	{
    		RandomListNode *pCloned = new RandomListNode(pNode -> label);
    		// pCloned -> label = pNode -> label;
    		pCloned -> next = pNode -> next;
    		pNode -> next = pCloned;
    		pNode = pCloned -> next;
    	}
    }

    void ConnectRandomNodes(RandomListNode *pHead)
    {
    	RandomListNode *pNode = pHead;
    	while(pNode != NULL)
    	{
    		RandomListNode *pCloned = pNode -> next;
    		if(pNode -> random != NULL)
    		{
    			pCloned -> random = pNode -> random -> next;
    		}
    		pNode = pCloned -> next;
    	}
    }

    RandomListNode *ReconnectNodes(RandomListNode *pHead)
    {
    	RandomListNode *pNode = pHead;
    	RandomListNode *pClonedHead = nullptr;
    	RandomListNode *pClonedNode = nullptr;

    	if(pNode != NULL)
    	{
    		pClonedHead = pClonedNode = pNode -> next;
    		pNode -> next = pClonedNode -> next;
    		pNode = pNode -> next;
    	}

    	while(pNode != NULL)
    	{
    		pClonedNode -> next = pNode -> next;
    		pClonedNode = pClonedNode -> next;
    		pNode -> next = pClonedNode -> next;
    		pNode = pNode -> next;
    	}
    	return pClonedHead;
    }
    RandomListNode* Clone(RandomListNode* pHead)
    {
    	CloneNodes(pHead);
    	ConnectRandomNodes(pHead);
    	return ReconnectNodes(pHead);
    }

};

int main()
{
    RandomListNode *node1 = new RandomListNode(1);
    RandomListNode *node2 = new RandomListNode(2);
    RandomListNode *node3 = new RandomListNode(3);
    RandomListNode *node4 = new RandomListNode(4);
    RandomListNode *node5 = new RandomListNode(5);

    RandomListNode *new_head = nullptr;
    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    node1 -> random = node3;
    node5 -> random = node2;

    Solution solution;
    new_head = solution.Clone(node1);
    while(new_head)
    {
        //cout << new_head -> label << " ";
        if(new_head -> random) cout << new_head -> label << "->random = " << new_head -> random -> label << endl;
        new_head = new_head -> next;
    }
    cout << endl;

    return 0;
}

// Description:
// 输入一个复杂链表（每个节点中有节点值，以及两个指针，
// 一个指向下一个节点，另一个特殊指针指向任意一个节点），
// 返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）

// Notice:
// cannot break the original linked list 
// otherwise the background cannot judge whether 
// you have created a new linked list
// or just reference the original linked list 
// for it cannot find the address of the node in original linked list 