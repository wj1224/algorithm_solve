# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        if head is None or head.next is None or k == 0:
            return head
        stack = []
        cur_node = head
        
        while cur_node.next is not None:
            stack.append(cur_node)
            cur_node = cur_node.next
        stack.append(cur_node)
        if k % len(stack) == 0:
            return head
        
        idx = len(stack) - (k % len(stack))
        head = stack[idx]
        stack.pop(idx)
        cur_node = head
        while idx < len(stack):
            cur_node.next = stack[idx]
            stack.pop(idx)
            cur_node = cur_node.next
        while len(stack) != 0:
            cur_node.next = stack[0]
            stack.pop(0)
            cur_node = cur_node.next
        cur_node.next = None
            
        return head
