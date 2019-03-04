
# -*- coding:utf-8 -*-
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def EntryNodeOfLoop(self, pHead):
        # write code here
        if pHead is None or pHead.next is None:
            return None
        p_slow = pHead
        p_fast = pHead
        while p_fast and p_fast.next:
            p_slow = p_slow.next
            p_fast = p_fast.next.next
            if p_slow == p_fast:
                p_slow = pHead
                while p_slow != p_fast:
                    p_slow = p_slow.next
                    p_fast = p_fast.next
                return p_slow
        return None

 
# l: not in loop length 
# r: loop length
# t: meet length in loop 
# n: num loop 

# l + nr + t = 2(l + t)
# l + t = nr 
# once meet in the loop:
# p_slow go back to pHead
# p_fast continue but move one step every time
# they will meet again

# since the first time meeting steps (l + t) 
# is the loop node numbers

# equal to: p_fast first move the loop numbers steps
#     	  then move with s_slow one step each time
#     	  they will meet again