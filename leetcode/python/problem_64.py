class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        n, m = len(grid), len(grid[0])
        mem = [[0 for _ in range(m)] for _ in range(n)]
        
        mem[0][0] = grid[0][0]
        for i in range(n):
            for j in range(m):
                if i == 0 and j == 0:
                    continue
                elif i == 0:
                    mem[i][j] = mem[i][j - 1] + grid[i][j]
                elif j == 0:
                    mem[i][j] = mem[i - 1][j] + grid[i][j]
                else:
                    mem[i][j] = min(mem[i - 1][j], mem[i][j - 1]) + grid[i][j]
                
        return mem[n - 1][m - 1]
