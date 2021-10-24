def solution(n, k, cmd):
    class Node:
        def __init__(self, data):
            self.data = data
            self.prev = None
            self.next = None

        def pop(self, cache):
            if self.prev is not None and self.next is not None:
                self.prev.next = self.next
                self.next.prev = self.prev
                cache.append(self)
                return self.next
            elif self.prev is None:
                self.next.prev = None
                cache.append(self)
                return self.next
            elif self.next is None:
                self.prev.next = None
                cache.append(self)
                return self.prev

    def restore(node):
        if node.prev is not None:
            node.prev.next = node
        if node.next is not None:
            node.next.prev = node

    answer = ['X'] * n
    cache = []

    for i in range(n):
        if i == 0:
            prev = Node(0)
            continue
        cur = Node(i)
        if i == k:
            idx = cur
        prev.next = cur
        cur.prev = prev
        prev = cur

    for c in cmd:
        if c[0] == "D":
            for _ in range(int(c[2:])):
                idx = idx.next
        elif c[0] == "U":
            for _ in range(int(c[2:])):
                idx = idx.prev
        elif c[0] == "C":
            idx = idx.pop(cache)
        elif c[0] == "Z":
            restore(cache.pop())

    while idx:
        head = idx
        idx = idx.prev

    while head:
        answer[head.data] = "O"
        head = head.next
    answer = ''.join(answer)

    return answer
