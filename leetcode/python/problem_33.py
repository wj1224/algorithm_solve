class Solution:
	def search(self, nums: List[int], target: int) -> int:
		if target not in nums:
			return -1
		
		left, right = 0, len(nums) - 1
		
		while True:
			mid = (left + right) // 2
			if nums[mid] == target:
				break
			if nums[left] <= nums[mid]:
				if nums[left] <= target and target < nums[mid]:
					right = mid - 1
				else:
					left = mid + 1
			else:
				if nums[mid] < target and target <= nums[right]:
					left = mid + 1
				else:
					right = mid - 1
		return mid
