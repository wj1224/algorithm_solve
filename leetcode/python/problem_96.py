import functools

class Solution:
    def numTrees(self, n: int) -> int:
        @functools.lru_cache()
        def solve(n):
            if n == 0 or n == 1:
                return 1
            answer = 0
            for i in range(n):
                answer += (solve(i) * solve(n - i - 1))
            return answer
        return solve(n)
