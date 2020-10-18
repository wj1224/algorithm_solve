def convert(num, n):
    n_num = []
    num_to_str = {10: 'A', 11: 'B', 12: 'C', 13: 'D', 14: 'E', 15: 'F'}

    while num:
        mod = num % n
        num //= n
        if mod < 10:
            n_num += str(mod)
        else:
            n_num += num_to_str[mod]
    
    if not n_num:
        n_num.append('0')
    
    return reversed(n_num)
    
def solution(n, t, m, p):
    answer = ''
    num = []
    
    for i in range(t * m):
        num += convert(i, n)
    
    while t:
        answer += num[p - 1]
        p += m
        t -= 1
    
    return answer
