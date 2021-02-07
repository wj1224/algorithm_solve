import operator

class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = []
        op = {'+': operator.add, '-': operator.sub, '*': operator.mul, '/': operator.truediv}
        for i in range(len(tokens)):
            if tokens[i] in op:
                num1 = s.pop()
                num2 = s.pop()
                res = int(op[tokens[i]](num2, num1))
                s.append(res)
            else:
                s.append(int(tokens[i]))
        
        return s.pop()
