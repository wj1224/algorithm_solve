# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None:
            return None
        s = []
        cur_node = head
        prev_node = None
        pass_val = -999999
        
        while cur_node is not None:
            if prev_node is not None and cur_node.val != prev_node.val and prev_node.val != pass_val:
                prev_node.next = None
                s.append(prev_node)
            elif prev_node is not None and prev_node.val != pass_val:
                pass_val = prev_node.val
            prev_node = cur_node
            if cur_node.next is not None:
                cur_node = cur_node.next
            else:
                break
        if pass_val != cur_node.val:
            cur_node.next = None
            s.append(cur_node)
        if len(s) == 0:
            return None
        head = s.pop(0)
        cur_node = head
        while len(s) != 0:
            cur_node.next = s.pop(0)
            cur_node = cur_node.next
        return head
