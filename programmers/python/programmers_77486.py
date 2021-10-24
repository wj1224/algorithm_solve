from collections import defaultdict

def solution(enroll, referral, seller, amount):
    answer = []
    whos = dict()
    resdict = defaultdict(int)
    
    for i in range(len(enroll)):
        whos[enroll[i]] = referral[i]
        
    for i in range(len(seller)):
        target = seller[i]
        owns = amount[i] * 100
        while target != "-":
            if owns == 0:
                break
            temp = owns
            owns = owns - int(owns * 0.1) if int(owns * 0.1) >= 1 else owns
            redund = temp - owns
            resdict[target] += owns
            owns = redund
            target = whos[target]
    
    for e in enroll:
        answer.append(resdict[e])
        
    return answer
