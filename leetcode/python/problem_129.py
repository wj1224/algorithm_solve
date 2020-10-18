# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if isinstance(root, type(None)):
            return 0
        
        rtol = []
        
        def search(node, curPath):
            if node.left is None and node.right is None:
                rtol.append(curPath)
                return
            
            if not node.left is None:
                search(node.left, curPath + str(node.left.val))
                
            if not node.right is None:
                search(node.right, curPath + str(node.right.val))
                
            return
        
        search(root, str(root.val))
        answer = sum(map(int, rtol))

        return answer
