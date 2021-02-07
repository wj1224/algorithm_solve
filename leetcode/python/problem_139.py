import re

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordDict = set(wordDict)
        mem = [False] * len(s)
        
        for i in range(len(s)):
            if i == 0 or mem[i - 1]:
                for j in range(i, len(s)):
                    if s[i:j + 1] in wordDict:
                        mem[j] = True
                
        return mem[-1]
