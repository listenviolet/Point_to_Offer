# include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode *dummy = new ListNode(-1);
        dummy -> next = pHead;
        ListNode *pre = dummy;
        ListNode *p1 = pHead;
        ListNode *p2 = p1 -> next;
        while(p1 != NULL && p2 != NULL)
        {
            if(p1 -> val == p2 -> val) 
            {
                while(p2 != NULL && p1 -> val == p2 -> val)
                {
                    p2 = p2 -> next;
                }


                pre -> next = p2;
                // if(p2 == NULL) cout << "p2 = null" << endl;
                if(p2 == NULL) break;
                p1 = p2;
                p2 = p1 -> next;
            }
            else
            {
                pre = p1;
                p1 = p2;
                p2 = p1 -> next;
            }
        }
        return dummy -> next;
    }
};

int main()
{
	// ListNode *n1 = new ListNode(1);
	// ListNode *n2 = new ListNode(2);
	// ListNode *n3 = new ListNode(3);
	// ListNode *n4 = new ListNode(3);
	// ListNode *n5 = new ListNode(4);
	// ListNode *n6 = new ListNode(4);
	// ListNode *n7 = new ListNode(5);

	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(1);
	ListNode *n3 = new ListNode(1);
	ListNode *n4 = new ListNode(1);
	ListNode *n5 = new ListNode(1);
	ListNode *n6 = new ListNode(1);
	ListNode *n7 = new ListNode(1);
	
	n1 -> next = n2;
	n2 -> next = n3;
	n3 -> next = n4;
	n4 -> next = n5;
	n5 -> next = n6;
	n6 -> next = n7;

	Solution solution;
	ListNode *pHead = nullptr;
	pHead = solution.deleteDuplication(n1);
	if(pHead == NULL) cout << "null" << endl;
	else
	{
		while(pHead != NULL)
		{
			cout << pHead -> val << " ";
			pHead = pHead -> next;
		}
	}
	
	return 0;
}

// 题目描述
// 在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，重复的结点不保留，返回链表头指针。 
// 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5

// 运行时间：4ms
// 占用内存：596k

// Notice:
// in while:
// while(p2 != NULL && p1 -> val == p2 -> val)
// add p2 != NULL 
// else if p2 == NULL, there is no p2 -> val
// this would cause segment fault.