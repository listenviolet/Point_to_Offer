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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode *fast = pListHead, *slow = pListHead;
        while(--k && fast)
        {
            fast = fast -> next;
        }
        if(fast == NULL) return NULL;
        while(fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;
    }
};