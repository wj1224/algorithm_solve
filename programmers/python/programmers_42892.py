import sys
sys.setrecursionlimit(10**6)

def solution(nodeinfo):
    class treeNode:
        def __init__(self, x=0, y=0, idx=0, left=None, right=None):
            self.x = x
            self.y = y
            self.idx = idx
            self.left = left
            self.right = right
    
    def addNode(pNode, cNode):
        if cNode.x < pNode.x:
            if pNode.left is None:
                pNode.left = cNode
            else:
                addNode(pNode.left, cNode)
        else:
            if pNode.right is None:
                pNode.right = cNode
            else:
                addNode(pNode.right, cNode)
                
    def preorder(node):
        if node is None:
            return
        answer[0].append(node.idx)
        preorder(node.left)
        preorder(node.right)
    
    def postorder(node):
        if node is None:
            return
        postorder(node.left)
        postorder(node.right)
        answer[1].append(node.idx)
            
    answer = [[], []]
    nodes = []
    
    for i in range(len(nodeinfo)):
        nodes.append([nodeinfo[i][0], nodeinfo[i][1], i + 1])
    nodes = sorted(nodes, key=lambda x: (-x[1], x[0]))
    root = treeNode(nodes[0][0], nodes[0][1], nodes[0][2])
    for n in nodes[1:]:
        addNode(root, treeNode(n[0], n[1], n[2]))
    preorder(root)
    postorder(root)
    
    return answer
