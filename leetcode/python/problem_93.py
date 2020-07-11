class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        self.answer = []
        self.solve(0, 0, s, "", "")
        return self.answer
        
    def solve(self, idx, cnt, s, subs, addr):
        if len(subs) >= 2 and subs[0] == "0":
            return
        if idx >= len(s):
            if cnt == 3:
                self.answer.append(addr + subs)
            return
        if int(subs + s[idx]) <= 255:
            self.solve(idx + 1, cnt, s, subs + s[idx], addr)
        if cnt < 3 and len(subs) != 0:
            self.solve(idx + 1, cnt + 1, s, s[idx], addr + subs + ".")
