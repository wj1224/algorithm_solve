class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mem = [[0 for _ in range(m + 2)] for _ in range(n + 2)]
        mem[0][1] = 1
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                mem[i][j] = mem[i - 1][j] + mem[i][j - 1]
                
        return mem[n][m]
