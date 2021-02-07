from collections import OrderedDict

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.lru = OrderedDict()

    def get(self, key: int) -> int:
        if not key in self.lru.keys():
            return -1
        
        val = self.lru.pop(key)
        self.lru[key] = val
        return val

    def put(self, key: int, value: int) -> None:
        if not key in self.lru.keys():
            if len(self.lru) >= self.capacity:
                self.lru.popitem(last=False)
        else:
            val = self.lru.pop(key)
        self.lru[key] = value


# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
