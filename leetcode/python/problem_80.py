class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        cur, cnt = -9999999, 0
        for i in reversed(range(len(nums))):
            if cur != nums[i]:
                cur = nums[i]
                cnt = 1
            else:
                cnt += 1
            if cnt > 2:
                nums.pop(i)
