class Solution:
	def threeSum(self, nums: List[int]) -> List[List[int]]:
		answer = []
		nums.sort()
		
		for i in range(len(nums) - 2):
			fix = nums[i]
			if fix > 0 or nums[-1] < 0:
				break
			if i >= 1 and fix == nums[i - 1]:
				continue
			left, right = i + 1, len(nums) - 1
			while left < right:
				t_sum = fix + nums[left] + nums[right]
				if t_sum == 0:
					answer.append([fix, nums[left], nums[right]])
					while left < right and nums[left] == nums[left + 1]:
						left += 1
					while left < right and nums[right] == nums[right - 1]:
						right -= 1
					left += 1
					right -= 1
				elif t_sum < 0:
					left += 1
				else:
					right -= 1
		
		return answer
