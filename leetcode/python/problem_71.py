class Solution:
    def simplifyPath(self, path: str) -> str:
        abs_path = path.split('/')
        can_path = []
        
        for i in range(len(abs_path)):
            if abs_path[i] == "" or abs_path[i] == ".":
                continue
            elif abs_path[i] == "..":
                if len(can_path) != 0:
                    can_path.pop()
                else:
                    continue
            else:
                can_path.append(abs_path[i])
        return '/' + '/'.join(can_path)
