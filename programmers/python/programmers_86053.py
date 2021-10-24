def solution(a, b, g, s, w, t):
    answer = 10 ** 19 * 2 + 1
    left, right = 0, 10 ** 19 * 2

    while left <= right:
        mid = (left + right) // 2

        total_gold = total_silver = total = 0
        for gold, silver, weight, times in zip(g, s, w, t):
            total_move = mid // (times * 2) + 1 if mid % (times * 2) >= times else mid // (times * 2)
            total_gold += weight * total_move if gold > total_move * weight else gold
            total_silver += weight * total_move if silver > total_move * weight else silver
            total += weight * total_move if gold + silver > total_move * weight else gold + silver

        if total_gold >= a and total_silver >= b and total >= a + b:
            right = mid - 1
            answer = min(answer, mid)
        else:
            left = mid + 1

    return answer
