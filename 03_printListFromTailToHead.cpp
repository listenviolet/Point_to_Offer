/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
class Solution {
public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode *node = head;
        while(node != NULL)
        {
            st.push(node);
            node = node -> next;
        }
        
        while(!st.empty())
        {
            ret.push_back(st.top() -> val);
            st.pop();
        }
        return ret;
    }
private:
    stack<ListNode *> st;
    vector<int> ret;
};

// 3. 从尾到头打印链表
// 输入一个链表，按链表值从尾到头的顺序返回一个ArrayList。

// 运行时间：3ms

// 占用内存：504k

