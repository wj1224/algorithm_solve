class Solution:
	def __init__(self):
		self.res = []
		
	def generateParenthesis(self, n: int) -> List[str]:
		self.solve(0, n * 2, n, n, "")
		return self.res
		
	def solve(self, idx, n, left, right, paren):
		if idx == n and left == 0 and right == 0:
			self.res.append(paren)
			return
		
		if left > 0:
			self.solve(idx + 1, n, left - 1, right, paren + "(")
		if right > 0 and right > left:
			self.solve(idx + 1, n, left, right - 1, paren + ")")
		return
