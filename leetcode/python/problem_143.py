# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reorderList(self, head: ListNode) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        if not head:
            return head
        ndict = {}
        idx = 0
        node = head
        
        while node:
            ndict[idx] = node
            node = node.next
            idx += 1
            
        for i in range(idx // 2):
            ndict[i].next = ndict[idx - i - 1]
        for i in range(idx - 1, idx // 2, -1):
            ndict[i].next = ndict[idx - i]
        ndict[idx // 2].next = None
