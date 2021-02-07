# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        self.answer = []
        self.postorder(root)
        return self.answer
        
    def postorder(self, node):
        if not node:
            return
        
        self.postorder(node.left)
        self.postorder(node.right)
        self.answer.append(node.val)
