from collections import deque

def solution(board):
    N = len(board)
    check = [[float('INF') for _ in range(N)] for _ in range(N)]
    check[0][0] = 0
    dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
    q = deque([[0, 0, 0, -1]]) # [money, x, y, dir]
    
    while q:
        money, x, y, d = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < N and nx >= 0 and ny < N and ny >= 0 and board[ny][nx] != 1:
                if (d == -1 or i == d) and money + 100 <= check[ny][nx]:
                    q.append([money + 100, nx, ny, i])
                    check[ny][nx] = money + 100
                elif (i != d and abs(i - d) != 2) and money + 600 <= check[ny][nx]:
                    q.append([money + 600, nx, ny, i])
                    check[ny][nx] = money + 600
                else:
                    continue

    return check[N - 1][N - 1]
