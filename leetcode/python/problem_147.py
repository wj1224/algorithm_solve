# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if isinstance(head, type(None)):
            return head
        
        insNode = head
        sorNode = ListNode()
        curNode = sorNode
        
        while insNode:
            nexNode = insNode.next
            
            while curNode.next != None and curNode.next.val < insNode.val:
                curNode = curNode.next
                
            insNode.next = curNode.next
            curNode.next = insNode
            curNode = sorNode
            insNode = nexNode
            
        return sorNode.next
