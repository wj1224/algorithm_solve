# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def recoverTree(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        def search(node, minnode, maxnode):
            if not isinstance(node, type(None)):
                if node.val < minnode.val and node.val < maxnode.val:
                    swapped.append(node)
                    swapped.append(minnode)
                elif node.val > minnode.val and node.val > maxnode.val:
                    swapped.append(node)
                    swapped.append(maxnode)
                search(node.left, minnode, node if node.val < maxnode.val else maxnode)
                search(node.right, node if node.val > minnode.val else minnode, maxnode)
        
        swapped = []
        search(root, TreeNode(float('-inf')), TreeNode(float('inf')))
        maxnode = max(swapped, key = lambda x: x.val)
        minnode = min(swapped, key = lambda x: x.val)
        minnode.val, maxnode.val = maxnode.val, minnode.val
