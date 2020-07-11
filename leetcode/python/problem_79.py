class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        answer = False
        s = []
        check = []
        dy, dx = [0, 1, 0, -1], [1, 0, -1, 0]
        
        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == word[0]:
                    s.append([word[0], 0, i, j])
                    
        while len(s) != 0:
            char, idx, y, x = s.pop()
            check.append([y, x])
            if char == word:
                answer = True
                break
            flag = False
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if nx >= 0 and nx < len(board[0]) and ny >= 0 and ny < len(board):
                    if board[ny][nx] == word[idx + 1] and [ny, nx] not in check:
                        s.append([char + word[idx + 1], idx + 1, ny, nx])
                        flag = True
            if flag is not True:
                if len(s) != 0:
                    while len(check) > s[-1][1]:
                        check.pop()
                else:
                    check.pop()
        return answer
