from functools import lru_cache

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1_len, s2_len, s3_len = len(s1), len(s2), len(s3)
        @lru_cache(None)
        def dp(i, j):
            if s1_len + s2_len != s3_len:
                return False
            if i == 0 and j == 0:
                return True
            elif i == 0:
                return dp(i, j - 1) and s2[j - 1] == s3[i + j - 1]
            elif j == 0:
                return dp(i - 1, j) and s1[i - 1] == s3[i + j - 1]
            else:
                return (dp(i, j - 1) and s2[j - 1] == s3[i + j - 1]) or \
                        (dp(i - 1, j) and s1[i - 1] == s3[i + j - 1])
            
        return dp(s1_len, s2_len)
