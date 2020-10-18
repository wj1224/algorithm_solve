# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        if not head:
            return
        
        sortedlist = []
        while head:
            sortedlist.append(head.val)
            head = head.next
        
        bst = self.solve(sortedlist)
        
        return bst
            
    def solve(self, sortedlist):
        if sortedlist:
            rootidx = len(sortedlist) // 2
            root = TreeNode(sortedlist[rootidx])
            root.left = self.solve(sortedlist[:rootidx])
            root.right = self.solve(sortedlist[rootidx + 1:])

            return root
