class Solution:
	def threeSumClosest(self, nums: List[int], target: int) -> int:
		if len(nums) < 3:
			return 0
		nums.sort()
		closest = nums[0] + nums[1] + nums[2]
		
		for left in range(len(nums) - 2):
			mid = left + 1
			right = len(nums) - 1
			while mid < right:
				three_sum = nums[left] + nums[mid] + nums[right]
				if three_sum == target:
					return three_sum
				if abs(three_sum - target) < abs(closest - target):
					closest = three_sum
				if three_sum < target:
					mid += 1
				else:
					right -= 1
		return closest
