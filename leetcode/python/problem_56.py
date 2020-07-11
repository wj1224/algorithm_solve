class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return []
        answer = []
        stack = []
        
        intervals.sort()
        for i in range(len(intervals)):
            if len(stack) == 0:
                stack.append(intervals[i][0])
                stack.append(intervals[i][1])
                continue
            if intervals[i][0] <= stack[-1]:
                temp = stack.pop()
                stack.append(max(temp, intervals[i][1]))
            else:
                answer.append([stack[0], stack[1]])
                stack.clear()
                stack.append(intervals[i][0])
                stack.append(intervals[i][1])
        answer.append([stack[0], stack[1]])
        return answer
