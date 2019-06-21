/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead == NULL) return NULL;
        ListNode *fast = pHead;
        ListNode *slow = pHead;
        if(fast -> next != NULL) fast = (fast -> next) -> next;
        slow = slow -> next;
        while(fast != slow && fast -> next != NULL)
        {
            fast = (fast -> next) -> next;
            slow = slow -> next;
        }
        
        if(fast == NULL || fast -> next == NULL) return NULL;
        slow = pHead;
        while(fast != slow)
        {
            fast = fast -> next;
            slow = slow -> next;
        }
        return fast;
    }
};

// 运行时间：3ms
// 占用内存：476k

// 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
//    *meet

// |-----|
// |     |
// |-----|
// | t
// |

// before entrance length = t;
// round length = r;
// entrance to meet point length = l;
 
// t + r + l = 2 * (t + l)
// r = t + l

// len(meet to entrance) = len(start to entrance)

// use fast and slow pointer to find the meet point 

// use two pointers, 
// one from meet to entrance
// one from start to entrance 
// both step = 1
// to find the entrance point