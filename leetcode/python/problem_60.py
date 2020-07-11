class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        factorial = 1
        nums = []
        answer = ""
        
        for i in range(1, n + 1):
            factorial *= i
            nums.append(i)
        
        for i in range(n):
            factorial //= (n - i)
            idx = (k - 1) // factorial
            answer += str(nums[idx])
            nums.pop(idx)
            k %= factorial
            
        return answer
