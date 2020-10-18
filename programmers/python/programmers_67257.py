from collections import deque

def solution(expression):
    answer = 0
    num = deque()
    oper = deque()
    prefer = [['+', '-', '*'],
              ['+', '*', '-'],
              ['-', '+', '*'],
              ['-', '*', '+'],
              ['*', '+', '-'],
              ['*', '-', '+']]
    
    for i in range(len(prefer)):
        for j in range(len(expression)):
            if j == 0:
                temp = ''
            if expression[j].isdigit():
                temp += expression[j]
            else:
                oper.append(expression[j])
                num.append(int(temp))
                temp = ''
        num.append(int(temp))

        for prefer_oper in prefer[i]:
            nstack = deque()
            ostack = deque()
            nstack.append(num.popleft())
            while oper:
                num_temp1 = num.popleft()
                oper_temp = oper.popleft()
                if oper_temp == prefer_oper:
                    num_temp2 = nstack.pop()
                    nstack.append(operation(oper_temp, num_temp2, num_temp1))
                else:
                    nstack.append(num_temp1)
                    ostack.append(oper_temp)
            num = nstack
            oper = ostack

        answer = max(answer, abs(num.popleft()))
            
    return answer

def operation(op, n1, n2):
    if op == '+':
        return n1 + n2
    elif op == '-':
        return n1 - n2
    elif op == '*':
        return n1 * n2
    else:
        pass
