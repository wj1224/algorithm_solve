# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        node = head
        ndict = {}
        
        while node:
            if node.next in ndict.keys():
                return node.next
            ndict[node] = node.next
            node = node.next
        
        return None
