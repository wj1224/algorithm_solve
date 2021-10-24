class Solution:
    def jump(self, nums: List[int]) -> int:
        res = idx = mem = 0
        
        for i in range(len(nums) - 1):
            mem = max(mem, i + nums[i])
            if idx == i:
                res += 1
                idx = mem
        return res
