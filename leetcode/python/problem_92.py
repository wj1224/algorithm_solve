# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        if head is None:
            return None
        cur_node = head
        idx = 1
        node = []
        start_node, end_node = None, None
        
        while cur_node is not None:
            if idx == m - 1:
                start_node = cur_node
            elif idx == n + 1:
                end_node = cur_node
            if idx >= m and idx <= n:
                node.append(cur_node)
            cur_node = cur_node.next
            idx += 1
        
        if start_node is not None:
            cur_node = start_node
        else:
            cur_node = node.pop()
            head = cur_node
        while len(node) != 0:
            cur_node.next = node.pop()
            cur_node = cur_node.next
        cur_node.next = end_node if end_node is not None else None
        
        return head
