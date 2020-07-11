# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        
        def findtree(nlist):
            if len(nlist) == 0:
                return [None]
            answer = []
            for i in range(len(nlist)):
                for l in findtree(nlist[:i]):
                    for r in findtree(nlist[i + 1:]):
                        node, node.left, node.right = TreeNode(nlist[i]), l, r
                        answer.append(node)
            return answer
        
        return findtree([x for x in range(1, n + 1)])
