class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.answer = []
        self.solve(1, n, k, [])
        return self.answer
        
    def solve(self, idx, n, k, comb):
        if len(comb) == k:
            self.answer.append(comb)
            return
        if idx > n:
            return
        self.solve(idx + 1, n, k, comb + [idx])
        self.solve(idx + 1, n, k, comb)
