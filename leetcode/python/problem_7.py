class Solution:
    def reverse(self, x: int) -> int:
        answer = int(str(x)[::-1]) if x >= 0 else -int(str(x)[1:][::-1])
        return answer if (answer >= -(2 ** 31) and answer <= (2 ** 31 - 1)) else 0
