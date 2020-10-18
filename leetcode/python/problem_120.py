class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        answer = triangle[-1]
        
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                answer[j] = min(answer[j], answer[j + 1]) + triangle[i][j]
        
        return answer[0]
