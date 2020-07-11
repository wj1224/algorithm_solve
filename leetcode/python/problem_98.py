# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        def treesearch(node, minval, maxval):
            if node is None:
                return True
            if minval <= node.val or maxval >= node.val:
                return False
            return treesearch(node.left, min(minval, node.val), maxval) and \
                   treesearch(node.right, minval, max(maxval, node.val))
        return treesearch(root, 9999999999, -9999999999)
