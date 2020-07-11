class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.answer = []
        self.solve(0, nums, [], True)
        return self.answer
        
    def solve(self, idx, nums, subset, flag):
        if flag is True:
            self.answer.append(subset)
        if idx >= len(nums):
            return
        self.solve(idx + 1, nums, subset + [nums[idx]], True)
        self.solve(idx + 1, nums, subset, False)
