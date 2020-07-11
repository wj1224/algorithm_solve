class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        dx, dy, idx, cnt = [1, 0, -1, 0], [0, 1, 0, -1], 0, 1
        answer = [[-1 for _ in range(n)] for _ in range(n)]
        
        x, y = 0, 0
        answer[y][x] = cnt
        cnt += 1
        while cnt <= n ** 2:
            nx = x + dx[idx]
            ny = y + dy[idx]
            if nx >= 0 and nx < n and ny >= 0 and ny < n and answer[ny][nx] == -1:
                x, y = nx, ny
                answer[y][x] = cnt
                cnt += 1
            else:
                idx = idx + 1 if idx < 3 else 0
        return answer
