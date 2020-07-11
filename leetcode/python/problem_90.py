class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        self.answer = []
        self.solve(0, nums, [])
        return self.answer
        
    def solve(self, idx, nums, subset):
        if idx >= len(nums):
            if sorted(subset) not in self.answer:
                self.answer.append(sorted(subset))
            return
                
        self.solve(idx + 1, nums, subset + [nums[idx]])
        self.solve(idx + 1, nums, subset)
