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
        if root is None:
            return root
        
        def search_nNode(node):
            while node.next is not None:
                node = node.next
                if node.left is not None:
                    return node.left
                elif node.right is not None:
                    return node.right
                else:
                    pass
                
            return None
        
        lNode = root.left
        rNode = root.right
        
        if lNode is not None:
            if rNode is not None:
                lNode.next = rNode
            else:
                lNode.next = search_nNode(root)
        if rNode is not None:
            rNode.next = search_nNode(root)
            
        self.connect(rNode)
        self.connect(lNode)
        
        return root
