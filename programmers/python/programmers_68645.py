import functools
import sys
sys.setrecursionlimit(3000)

@functools.lru_cache()
def calc(n):
    if n <= 1:
        return n
    return n + calc(n - 1)

def solution(n):
    tri = [[0] * n for _ in range(n)]
    max_num = calc(n)
    x, y = 0, 0
    cnt = 0
    dir_cnt = n - 1
    dx = [1 ,0, -1]
    dy = [0, 1, -1]
    d = 1

    for i in range(1, max_num + 1):
        if cnt == dir_cnt:
            cnt = 0
            if i >= 2 * n - 1:
                dir_cnt -= 1
            if d == 0:
                d = 2
            elif d == 1:
                d = 0
            else:
                d = 1
        tri[y][x] = i
        x += dx[d]
        y += dy[d]
        cnt += 1

    return list(filter(lambda x: x != 0, sum(tri, [])))
