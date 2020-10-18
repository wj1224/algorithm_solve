from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root or (root.left is None and root.right is None):
            return root
        treenode = deque()
        
        def search(node):
            treenode.append(node)
            if node.left is not None:
                search(node.left)
            if node.right is not None:
                search(node.right)
                return

        search(root)
        node = root
        while treenode:
            node.right = treenode.popleft()
            node.left = None
            node = node.right
