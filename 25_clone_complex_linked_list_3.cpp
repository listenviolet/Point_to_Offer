/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        pHead = addNodes(pHead);
        return split(pHead);
    }
    
    RandomListNode* addNodes(RandomListNode *pHead)
    {
        RandomListNode *p1 = pHead;
        while(p1 != NULL)
        {
            RandomListNode *newNode = new RandomListNode(p1 -> label);
            newNode -> next = p1 -> next;
            p1 -> next = newNode;
            p1 = newNode -> next;
        }
        
        p1 = pHead;
        while(p1 != NULL)
        {
            if(p1 -> random != NULL) 
            {
                p1 -> next -> random = p1 -> random -> next;
            }
            p1 = p1 -> next -> next;
        }
        return pHead;
    }
    
    RandomListNode *split(RandomListNode *pHead)
    {
        RandomListNode *p1 = pHead;
        RandomListNode *clonedHead = nullptr;
        RandomListNode *p2 = nullptr;
        if(pHead != NULL) clonedHead = pHead -> next;
        
        while(p1 != NULL)
        {
            p2 = p1 -> next;
            p1 -> next = p2 -> next;
            p1 = p1 -> next;
            
            if(p2 -> next != NULL) 
            {
                p2 -> next = p1 -> next;
            }
            else p2 -> next = NULL;
        }
        
        return clonedHead;
    }
};

// 输入一个复杂链表（每个节点中有节点值，以及两个指针，
// 一个指向下一个节点，另一个特殊指针指向任意一个节点），
// 返回结果为复制后复杂链表的head。
// （注意，输出结果中请不要返回参数中的节点引用，
// 否则判题程序会直接返回空）

// 运行时间：4ms
// 占用内存：492k
