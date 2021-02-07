# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        self.answer = []
        self.preorder(root)
        return self.answer
        
    def preorder(self, node):
        if not node:
            return
        self.answer.append(node.val)
        self.preorder(node.left)
        self.preorder(node.right)
