class Solution:
	def searchRange(self, nums: List[int], target: int) -> List[int]:
		left, right = 0, len(nums) - 1
		mid = None
		
		while left <= right:
			mid = (left + right) // 2
			
			if nums[mid] < target:
				left = mid + 1
			elif nums[mid] > target:
				right = mid - 1
			else:
				break
		if mid == None or nums[mid] != target:
			return [-1, -1]
		
		left_idx = right_idx = mid
		while left_idx > 0 and nums[left_idx - 1] == target:
			left_idx -= 1
		while right_idx < len(nums) - 1 and nums[right_idx + 1] == target:
			right_idx += 1
		return [left_idx, right_idx]
