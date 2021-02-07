class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        nums_rev = list(reversed(nums))
        for i in range(1, len(nums)):
            nums[i] = nums[i] * nums[i - 1] if nums[i - 1] != 0 else nums[i]
            nums_rev[i] = nums_rev[i] * nums_rev[i - 1] if nums_rev[i - 1] != 0 else nums_rev[i]
        
        return max(nums + nums_rev)
