class Solution:
	def canJump(self, nums: List[int]) -> bool:
		if len(nums) == 1:
			return True
		max_pos = 0
		for pos, dist in enumerate(nums):
			max_pos = max(max_pos, pos + dist)
			if max_pos >= len(nums) - 1:
				return True
			if dist == 0 and max_pos == pos:
				return False
