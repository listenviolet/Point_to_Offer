/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        ListNode *p1 = pHead1, *p2 = pHead2;
        ListNode *dummy = new ListNode(-1);
        ListNode *p3 = dummy;
        while(p1 && p2)
        {
            if(p1 -> val < p2 -> val)
            {
                p3 -> next = new ListNode(p1 -> val);
                p3 = p3 -> next;
                p1 = p1 -> next;
            }
            else
            {
                p3 -> next = new ListNode(p2 -> val);
                p3 = p3 -> next;
                p2 = p2 -> next;
            }
        }
        if(p1)
        {
            p3 -> next = p1;
        }
        else if(p2)
        {
            p3 -> next = p2;
        }
        return dummy -> next;
    }
};