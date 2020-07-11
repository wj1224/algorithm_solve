class Solution:
	def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
		self.answer = []
		candidates.sort()
		self.solve(0, candidates, [], 0, target)
		return self.answer
		
	def solve(self, idx, candidates, comb, res, target):
		if res == target:
			self.answer.append(comb)
			return
		elif res > target or res + min(candidates) > target:
			return
		for i in range(idx, len(candidates)):
			self.solve(i, candidates, comb + [candidates[i]], res + candidates[i], target)
