def FindFirstCommonNode(pHead1, pHead2):
    length1, length2 = 0, 0
    p1 = pHead1
    p2 = pHead2
    while p1:
        length1 += 1
        p1 = p1.next
    while p2:
        length2 += 1
        p2 = p2.next
    p1 = pHead1
    p2 = pHead2
    if length1 > length2:
        cnt = length1 - length2
        while cnt > 0:
            p1 = p1.next
            cnt -= 1
    elif length1 < length2:
        cnt = length2 - length1
        while cnt > 0:
            p2 = p2.next
            cnt -= 1
    while p1 and (p1.val != p2.val):
        p1 = p1.next
        p2 = p2.next
    return p1