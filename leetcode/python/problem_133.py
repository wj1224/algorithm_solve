from collections import deque

"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node

        q = deque([node])
        new_node = {node: Node(node.val)}
        
        while q:
            ori_node = q.popleft()
            for i in range(len(ori_node.neighbors)):
                if ori_node.neighbors[i] not in new_node:
                    q.append(ori_node.neighbors[i])
                    new_node[ori_node.neighbors[i]] = Node(ori_node.neighbors[i].val)
                new_node[ori_node].neighbors.append(new_node[ori_node.neighbors[i]])

        return new_node[node]
