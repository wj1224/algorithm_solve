class Solution:
	def __init__(self):
		self.answer = []
		
	def letterCombinations(self, digits: str) -> List[str]:
		digits_to_letters = {"2": ["a", "b", "c"], "3": ["d", "e", "f"], "4": ["g", "h", "i"], 
							"5": ["j", "k", "l"], "6": ["m", "n", "o"], "7": ["p", "q", "r", "s"],
							"8": ["t", "u", "v"], "9": ["w", "x", "y", "z"]}
		self.dfs(len(digits), 0, digits, digits_to_letters, "")
		return self.answer
		
	def dfs(self, n, idx, digits, d, res):
		if idx == n:
			if len(res) != 0:
				self.answer.append(res)
			return
		for i in range(len(d[digits[idx]])):
			self.dfs(n, idx + 1, digits, d, res + d[digits[idx]][i])
