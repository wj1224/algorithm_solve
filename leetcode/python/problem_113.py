# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if not root:
            return
        answer = []
        
        def go(node, val, path):
            if node.left is None and node.right is None:
                if val + node.val == sum:
                    answer.append(path + [node.val])
            if node.left is not None:
                go(node.left, val + node.val, path + [node.val])
            if node.right is not None:
                go(node.right, val + node.val, path + [node.val])
            
            return
        
        go(root, 0, [])
        
        return answer
