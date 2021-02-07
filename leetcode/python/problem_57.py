class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        intervals.append(newInterval)
        intervals.sort()
        
        i = 0
        while i < len(intervals) - 1:
            cur_l, cur_r = intervals[i][0], intervals[i][1]
            next_l, next_r = intervals[i + 1][0], intervals[i + 1][1]
            if cur_l <= next_l and cur_r >= next_l:
                intervals[i][0] = cur_l
                intervals[i][1] = max(cur_r, next_r)
                intervals.pop(i + 1)
                i -= 1
            i += 1
        
        return intervals
