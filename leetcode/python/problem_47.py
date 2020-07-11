class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.answer = []
        nums.sort()
        self.solve(nums, [], [False for _ in range(len(nums))])
        return self.answer
 
    def solve(self, nums, res, check):
        if len(res) == len(nums):
            self.answer.append(res)
        for i in range(len(nums)):
            if i > 0 and nums[i - 1] == nums[i] and check[i - 1] is False:
                continue
            if check[i] is False:
                check[i] = True
                self.solve(nums, res + [nums[i]], check)
                check[i] = False
