# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
from collections import deque

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        answer = []
        q = deque()
        
        q.append((root, 0))
        while q:
            node, level = q.popleft()
            if len(answer) <= level:
                answer.append([node.val])
            else:
                answer[level].append(node.val)
            if node.left is not None:
                q.append((node.left, level + 1))
            if node.right is not None:
                q.append((node.right, level + 1))
        
        return answer
