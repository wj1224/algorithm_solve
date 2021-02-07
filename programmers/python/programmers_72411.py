from collections import defaultdict

def dfs(idx, order, cur, menu_cnt, max_cnt):
    num_cur = len(cur)
    if num_cur >= 2:
        menu_cnt[cur] += 1
        max_cnt[num_cur] = max(max_cnt[num_cur], menu_cnt[cur])
    else:
        pass

    for i in range(idx + 1, len(order)):
        dfs(i, order, cur + order[i], menu_cnt, max_cnt)

def solution(orders, course):
    answer = []
    menu_cnt = defaultdict(int)
    max_cnt = defaultdict(int)

    for order in orders:
        order = sorted(order)
        dfs(-1, order, "", menu_cnt, max_cnt)

    for c in course:
        for length, cnt in max_cnt.items():
            if length == c and cnt >= 2:
                for key, val in menu_cnt.items():
                    if len(key) == length and val == cnt:
                        answer.append(key)
            else:
                pass

    return sorted(answer)
