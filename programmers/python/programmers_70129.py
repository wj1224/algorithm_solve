def solution(s):
    answer = [0, 0]
    
    while s != "1":
        len_s = s.count("1")
        answer[1] += len(s) - len_s
        s = bin(len_s)[2:]
        answer[0] += 1
    
    return answer
