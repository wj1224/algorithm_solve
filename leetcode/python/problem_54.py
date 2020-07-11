class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        if len(matrix) == 0:
            return []
        answer, x, y, idx = [], 0, 0, 0
        dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
        m, n = len(matrix), len(matrix[0])
        check = [[False for _ in range(n)] for _ in range(m)]
        
        check[0][0] = True
        answer.append(matrix[0][0])
        while True:
            nx, ny = x + dx[idx], y + dy[idx]
            if nx >= 0 and nx < n and ny >= 0 and ny < m and check[ny][nx] is False:
                x = nx
                y = ny
                check[y][x] = True
                answer.append(matrix[y][x])
            else:
                idx = idx + 1 if idx < 3 else 0
            if len(answer) == m * n:
                break
        return answer
