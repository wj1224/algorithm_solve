class Solution:
    def partition(self, s: str) -> List[List[str]]:
        self.answer = []
        self.s_size = len(s)
        
        self.solve(s, 0, [])
        
        return self.answer
        
    def solve(self, s, idx, partition):
        if idx >= self.s_size:
            self.answer.append(partition)
            return
        
        for i in range(idx, self.s_size):
            if self.isPalindrome(s, idx, i):
                self.solve(s, i + 1, partition + [s[idx:i + 1]])
        
    def isPalindrome(self, s, start, end):
        while start <= end:
            if s[start] != s[end]:
                return False
            start += 1
            end -= 1
        return True
