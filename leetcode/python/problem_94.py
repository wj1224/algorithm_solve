# Definition for a binary tree node.
# class TreeNode:
#	  def __init__(self, x):
#		  self.val = x
#		  self.left = None
#		  self.right = None

class Solution:
	def __init__(self):
		self.answer = []
		
	def inorderTraversal(self, root: TreeNode) -> List[int]:
		self.inorder_(root)
		return self.answer
	
	def inorder_(self, node):
		if node is not None:
			self.inorder_(node.left)
			self.answer.append(node.val)
			self.inorder_(node.right)
