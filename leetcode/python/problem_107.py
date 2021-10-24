from collections import deque

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrderBottom(self, root: Optional[TreeNode]) -> List[List[int]]:
        if isinstance(root, type(None)):
            return []
        q = deque([root])
        levels = deque([0])
        answer = []
        
        while q:
            node = q.popleft()
            level = levels.popleft()
            try:
                answer[level].append(node.val)
            except:
                answer.append([node.val])
            if node.left is not None:
                q.append(node.left)
                levels.append(level + 1)
            if node.right is not None:
                q.append(node.right)
                levels.append(level + 1)
        
        return answer[::-1]
