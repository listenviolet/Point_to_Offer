# include<bits/stdc++.h>
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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        ListNode *p1 = pHead1;
        ListNode *p2 = pHead2;
        while(p1 != NULL && p2 != NULL)
        {
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        int flag = 1;
        int k = 0;
        if(p2 != NULL) flag = 2;
        while(p1 != NULL)
        {
            p1 = p1 -> next;
            k++;
        }
        while(p2 != NULL)
        {
            p2 = p2 -> next;
            k++;
        }
        
        p1 = pHead1, p2 = pHead2;
        if(flag == 1)
        {
            while(k--)
            {
                p1 = p1 -> next;
            }
        }
        else
        {
            while(k--)
            {
                p2 = p2 -> next;
            }
        }
        
        while(p1 != NULL && p2 != NULL)
        {
            if(p1 == p2) break;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }
        
        return p1;
    }
};

int main()
{
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(3);
    ListNode *node4 = new ListNode(4);
    ListNode *node5 = new ListNode(5);

    node1 -> next = node3;
    node3 -> next = node4;
    node4 -> next = node5;

    node2 -> next = node4;

    ListNode *res = nullptr;

    Solution solution;
    res = solution.FindFirstCommonNode(node1, node2);
    cout << res -> val << endl;
    return 0;
}

// 输入两个链表，找出它们的第一个公共结点。
// 运行时间：5ms

// 占用内存：456k