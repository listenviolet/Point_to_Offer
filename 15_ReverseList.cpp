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
    ListNode* ReverseList(ListNode* pHead) {
        if(pHead == NULL || pHead -> next == NULL) return pHead;
        ListNode *p1 = pHead, *p2 = p1->next;
        pHead -> next  = NULL;
        ListNode *p3 = nullptr;
        while(p2->next)
        {
            p3 = p2 -> next;
            p2 -> next = p1;
            p1 = p2;
            p2 = p3;
        }
        p2 -> next = p1;
        return p2;
    }
};