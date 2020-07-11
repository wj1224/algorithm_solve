# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if head is None:
            return None
        left = []
        right = []
        cur_node = head
        flag = False
        
        while cur_node is not None:
            if cur_node.val < x:
                left.append(cur_node)
            else:
                right.append(cur_node)
            cur_node = cur_node.next
        if len(left) != 0:
            flag = True
            head = left.pop(0)
            cur_node = head
        while len(left) != 0:
            cur_node.next = left.pop(0)
            cur_node = cur_node.next
        if len(right) != 0 and flag is True:
            cur_node.next = right.pop(0)
            cur_node = cur_node.next
        elif flag is not True:
            head = right.pop(0)
            cur_node = head
        while len(right) != 0:
            cur_node.next = right.pop(0)
            cur_node = cur_node.next
        cur_node.next = None
        return head
