# https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack:

    def __init__(self):
        self.table = defaultdict(int)
        self.stacks = []
        

    def push(self, val: int) -> None:
        self.table[val] += 1
        if self.table[val] > len(self.stacks):
            self.stacks.append([val])
        else:
            self.stacks[self.table[val] - 1].append(val)
    
    def pop(self) -> int:
        if not self.stacks[-1]:
            self.stacks.pop()
        x = self.stacks[-1].pop()

        self.table[x] -= 1
        return x
        

# Your FreqStack object will be instantiated and called as such:
# obj = FreqStack()
# obj.push(val)
# param_2 = obj.pop()
