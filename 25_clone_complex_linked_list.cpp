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
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == NULL)
            return NULL;

        RandomListNode *p = nullptr;
        vector<RandomListNode*> pList;
        p = pHead;
        while(p != NULL)
        {
            pList.push_back(p);
            RandomListNode *node = new RandomListNode(p -> label);
            // cout << node -> label << endl;
            node -> next = p -> next;
            p -> next = node;
            p = node -> next;

        }

        p = pHead;
        
        RandomListNode *p1 = nullptr;
        RandomListNode *p2 = nullptr;
        RandomListNode *new_head = new RandomListNode(-1);
        new_head -> next = pHead -> next;
        //p2 = new_head;
        p1 = pHead;
        while(p1 != NULL)
        {
            //p2 -> next = p1 -> next;
            p2 = p1 -> next;
            if(p1 -> random != NULL) 
                p2 -> random = p1 -> random -> next;
            
            p1 = p2 -> next;
            if(p1 != NULL) p2 -> next = p1 -> next;
            else p2 -> next = NULL;
        }

        for(decltype(pList.size()) i = 0; i < pList.size() - 1; ++i)
            pList[i]->next = pList[i + 1];
        if(pList.size() != 0)
            pList[pList.size() - 1]->next = nullptr;


        p2 = new_head -> next;
        //cout << "---" << endl;
        return new_head -> next;
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

    printf("%p\n", node1);
    printf("%p\n", node2);
    printf("%p\n", node3);
    printf("%p\n", node4);
    printf("%p\n", node5);

    Solution solution;
    new_head = solution.Clone(node1);
    printf("-----\n");
    while(new_head)
    {
        printf("%p\n", new_head);
        //cout << new_head -> label << " ";
        //if(new_head -> random) cout << new_head -> label << "->random = " << new_head -> random -> label << endl;
        new_head = new_head -> next;
    }
        printf("-----\n");

    while(node1)
    {
        printf("%p\n", node1);
        //cout << new_head -> label << " ";
        //if(new_head -> random) cout << new_head -> label << "->random = " << new_head -> random -> label << endl;
        node1 = node1 -> next;
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