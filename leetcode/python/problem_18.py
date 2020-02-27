class Solution:
	def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
		answer = []
		nums.sort()
		
		for i in range(len(nums) - 3):
			for j in range(len(nums) - 1, i + 2, -1):
				left = i + 1
				right = j - 1
				while left < right:
					four_sum = nums[i] + nums[j] + nums[left] + nums[right]
					if four_sum == target:
						answer.append((nums[i], nums[j], nums[left], nums[right]))
					if four_sum <= target:
						left += 1
					else:
						right -= 1
		return list(set(answer))
