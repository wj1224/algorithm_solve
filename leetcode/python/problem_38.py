class Solution:
    def countAndSay(self, n: int) -> str:
        def go(num):
            res = ""
            cnt = 1
            for i in range(len(num) - 1):
                if num[i] != num[i + 1]:
                    res += (str(cnt) + num[i])
                    cnt = 1
                else:
                    cnt += 1
            res += (str(cnt) + num[-1])
            
            return res
        
        answer = "1"
        for i in range(2, n + 1):
            answer = go(answer)
        return answer
