from collections import deque

class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        q = deque()
        q.append([beginWord, 1])
        wordList = set(wordList)
        charList = "abcdefghijklmnopqrstuvwxyz"
        answer = float('inf')
        
        if not endWord in wordList:
            return 0
        
        while q:
            curWord, cnt = q.popleft()
            if curWord == endWord:
                answer = min(answer, cnt)
                continue
            
            for i in range(len(curWord)):
                for c in charList:
                    newWord = curWord[:i] + c + curWord[i + 1:]
                    if newWord in wordList:
                        wordList.remove(newWord)
                        q.append([newWord, cnt + 1])
        
        return answer if answer !=  float('inf') else 0
