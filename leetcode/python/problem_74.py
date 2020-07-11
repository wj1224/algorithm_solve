class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        if len(matrix) == 0 or len(matrix[0]) == 0:
            return False
        x, y = 0, 0
        m, n = len(matrix), len(matrix[0])
        answer = False

        while True:
            if matrix[y][x] == target:
                answer = True
                break
            if y == m - 1 and x == n - 1:
                break
            if (y + 1 < m and matrix[y + 1][x] <= target) or x + 1 == n:
                y = y + 1
            elif (x + 1 < n and matrix[y][x + 1] <= target) or y + 1 == m:
                x = x + 1
            else:
                break
        return answer
