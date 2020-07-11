class Solution:
	def nextPermutation(self, nums: List[int]) -> None:
		"""
		Do not return anything, modify nums in-place instead.
		"""
		idx = -1
		for i in range(len(nums)):
			for j in range(i + 1, len(nums)):
				if nums[i] < nums[j]:
					idx = i
		
		if idx == -1:
			nums.sort()
		else:		
			for i in range(len(nums) - 1, idx, -1):
				if nums[i] > nums[idx]:
					nums[i], nums[idx] = nums[idx], nums[i]
					break
			nums[idx + 1:] = reversed(nums[idx + 1:])
