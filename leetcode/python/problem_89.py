class Solution:
    def grayCode(self, n: int) -> List[int]:
        answer = [0]
        
        for i in range(n):
            it = len(answer)
            for j in range(len(answer) - 1, -1, -1):
                answer.append(answer[j] | 1 << i)
        
        return answer
