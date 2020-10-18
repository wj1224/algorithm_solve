class Solution:
    def solve(self, board: List[List[str]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        def connection_search(x, y):
            dx = [1, 0, -1, 0]
            dy = [0, 1, 0, -1]
            s = []
            
            s.append([x, y])
            board[y][x] = 'Z'
            
            while s:
                cx, cy = s.pop()
                for i in range(4):
                    nx = cx + dx[i]
                    ny = cy + dy[i]
                    if nx < 0 or nx >= len(board[0]) or ny < 0 or ny >= len(board):
                        continue
                    if board[ny][nx] == 'O':
                        s.append([nx, ny])
                        board[ny][nx] = 'Z'
                       
        for i in range(len(board)):
            for j in range(len(board[0])):
                if (i == 0 or i == len(board) - 1 or j == 0 or j == len(board[0]) - 1) \
                and board[i][j] == 'O':
                    connection_search(j, i)
                            
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == 'Z':
                    board[i][j] = 'O'
                else:
                    board[i][j] = 'X'
