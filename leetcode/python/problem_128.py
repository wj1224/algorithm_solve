class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        nums = list(set(nums))
        nums.sort()
        cnt, maxcnt = 1, 0
        cur = nums[0]
        for num in nums[1:]:
            if num == cur + 1:
                cnt += 1
                cur += 1
            else:
                maxcnt = max(maxcnt, cnt)
                cur = num
                cnt = 1
        maxcnt = max(maxcnt, cnt)
        
        return maxcnt
