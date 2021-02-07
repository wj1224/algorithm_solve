# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        return self.merge_sort(head)
        
    def merge_sort(self, node):
        if not node or not node.next:
            return node
        
        front, slow, fast = None, node, node
        
        while fast and fast.next:
            front = slow
            slow = slow.next
            fast = fast.next.next
        front.next = None
        
        return self.merge(self.merge_sort(node), self.merge_sort(slow))
        
    def merge(self, left, right):
        dummy = cur = ListNode()
        
        while left and right:
            if left.val < right.val:
                cur.next = left
                left = left.next
            else:
                cur.next = right
                right = right.next
            cur = cur.next
        cur.next = left if left else right
        
        return dummy.next
