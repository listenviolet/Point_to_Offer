# -*- coding:utf-8 -*-
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def show(p):
    while p:
        print(p.val)
        p = p.next
    print('--------------')

def deleteDuplication(pHead):
    
    # write code here
    if not pHead: return
    p_null = ListNode(0)
    p_null.next = pHead
    p1 = p_null
    p2 = p1.next 
    while p2:
        if p2.next is None: return p_null.next
        if p2.next.val != p2.val: 
            p1 = p2
            p2 = p2.next
        elif p2.next is not None and p2.next.val == p2.val:
            while p2.next is not None and p2.next.val == p2.val:
                p2 = p2.next
            p1.next = p2.next
            p2 = p2.next
    return p_null.next

link = [1,2,3,3,4,4,5]
link = [1,1,1,1,1]
pHead = ListNode(link[0])
p1 = pHead
for i in range(1, len(link)):
    node = ListNode(link[i])
    p1.next = node 
    p1 = p1.next 

p = deleteDuplication(pHead)
show(p)

