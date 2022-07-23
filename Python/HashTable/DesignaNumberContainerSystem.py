# https://leetcode.com/problems/design-a-number-container-system/

from sortedcontainers import SortedList
class NumberContainers:

    def __init__(self):
        self.num2idx = defaultdict(SortedList)
        self.idx2num = {}
        

    def change(self, index: int, number: int) -> None:
        if index in self.idx2num:
            pre_num = self.idx2num[index]
            self.num2idx[pre_num].discard(index)
            
        self.idx2num[index] = number
        self.num2idx[number].add(index)

    def find(self, number: int) -> int:
        if number in self.num2idx and len(self.num2idx[number]) > 0:
            return self.num2idx[number][0]
        return -1
        
        


# Your NumberContainers object will be instantiated and called as such:
# obj = NumberContainers()
# obj.change(index,number)
# param_2 = obj.find(number)
