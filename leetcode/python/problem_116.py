"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""

class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if isinstance(root, type(None)) or isinstance(root.left, type(None)):
            return root
        
        prevNode = root
        lNode = root.left
        rNode = root.right
        
        lNode.next = rNode
        if prevNode.next is not None:
            rNode.next = prevNode.next.left

        self.connect(lNode)
        self.connect(rNode)
        
        return root
