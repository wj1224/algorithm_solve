import numpy as np

def solution(m, n, board):
    answer = 0
    flag = True
    dx, dy = [1, 1, 0], [0, 1, 1]
    for i in range(m):
        board[i] = list(board[i])
    board = np.transpose(np.array(board), (1, 0)).tolist()
    
    while True:
        d = dict()
        if flag is False:
            break
        flag = False
        q = []
        for i in range(m):
            for j in range(n):
                if board[j][i] == '0':
                    continue
                friend = board[j][i]
                temp = [[j, i]]
                for k in range(3):
                    nx = j + dx[k]
                    ny = i + dy[k]
                    if nx >= 0 and nx < n and ny >= 0 and ny < m:
                        if board[nx][ny] != friend:
                            break
                        temp.append([nx, ny])
                    else:
                        break
                else:
                    q += temp
        
        for i in range(len(q)):
            flag = True
            if board[q[i][0]][q[i][1]] != '0' and (str(q[i][0]) + ', ' + str(q[i][1])) not in d:
                d[str(q[i][0]) + ', ' + str(q[i][1])] = True
                board[q[i][0]].pop(q[i][1])
                board[q[i][0]].insert(0, '0')
                answer += 1
    return answer
