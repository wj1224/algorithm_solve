def solution(user_id, banned_id):
    temp = []
    check = []
    solve(user_id, banned_id, 0, 0, temp, check)
    return len(check)

def solve(user_id, banned_id, user_idx, banned_idx, temp, check):
    if banned_idx >= len(banned_id):
        temp = sorted(temp)
        if len(temp) == len(banned_id) and temp not in check:
            check.append(temp[:])
        return
        
    if user_idx >= len(user_id):
        solve(user_id, banned_id, 0, banned_idx + 1, temp, check)
        return
    
    flag = True
    if len(user_id[user_idx]) == len(banned_id[banned_idx]):
        for i in range(len(banned_id[banned_idx])):
            if user_id[user_idx][i] != banned_id[banned_idx][i] and banned_id[banned_idx][i] != "*":
                flag = False
                break
    else:
        flag = False
    if flag:
        temp.append(user_id.pop(user_idx))
        solve(user_id, banned_id, 0, banned_idx + 1, temp, check)
        user_id.insert(user_idx, temp.pop())
    solve(user_id, banned_id, user_idx + 1, banned_idx, temp, check)
