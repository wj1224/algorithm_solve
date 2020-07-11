class Solution:
	def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
		self.answer = []
		candidates.sort()
		self.solve(0, candidates, [], 0, target)
		return self.answer
		
	def solve(self, idx, candidates, comb, res, target):
		if res == target:
			if comb not in self.answer:
				self.answer.append(comb)
			return
		elif res > target or res + min(candidates) > target:
			return
		if idx >= len(candidates):
			return
		self.solve(idx + 1, candidates, comb + [candidates[idx]], res + candidates[idx], target)
		self.solve(idx + 1, candidates, comb, res, target)
