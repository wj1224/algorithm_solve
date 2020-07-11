class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        answer = dict()
        
        for i in range(len(strs)):
            temp = sorted(strs[i])
            temp = ''.join(temp)
            answer[temp] = answer.get(temp, []) + [strs[i]]
        return list(answer.values())
