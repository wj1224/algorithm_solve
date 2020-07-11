from itertools import combinations

def solution(relation):
    answer = set()
    comb = []
    for i in range(1, len(relation[0]) + 1):
        comb.append(list(combinations([x for x in range(len(relation[0]))], i)))
    
    def find_key(relation, comb, answer):
        for i in range(len(comb)):
            check = set()
            for j in range(len(relation)):
                temp = ''
                for k in comb[i]:
                    temp = temp + str(relation[j][k]) if isinstance(relation[j][k], int) else temp + relation[j][k] 
                check.add(temp)
            if len(check) == len(relation):
                answer.add(comb[i])
        return answer
    
    for idx in range(len(comb)):
        answer = find_key(relation, comb[idx], answer)
    
    def delete_key(answer):
        delete_set = set()
        for a in answer:
            a = set(a)
            for b in answer:
                b = set(b)
                if a is not b and a.issubset(b) and len(a) < len(b):
                    delete_set.add(tuple(b))
        return delete_set
        
    del_key = delete_key(answer)
    
    return len(answer - del_key)
