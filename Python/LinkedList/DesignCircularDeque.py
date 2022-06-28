# https://leetcode.com/problems/design-circular-deque/

class ListNode:
    
    def __init__(self, val = None):
        self.val = val
        self.next = None
        self.pre = None
        

class MyCircularDeque:

    def __init__(self, k: int):
        self.capacity = k
        self.size = 0
        self.pre = None
        self.end = None
        

    def insertFront(self, value: int) -> bool:
        if self.capacity <= self.size:
            return False
        if self.size == 0:
            self.pre = ListNode(value)
            self.end = self.pre
        else:
            node = ListNode(value)
            node.next = self.pre
            self.pre.pre = node
            self.pre = node
        self.size += 1
        return True
        

    def insertLast(self, value: int) -> bool:
        if self.capacity <= self.size:
            return False
        if self.size == 0:
            self.pre = ListNode(value)
            self.end = self.pre
        else:
            node = ListNode(value)
            node.pre = self.end
            self.end.next = node
            self.end = node
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.size == 0:
            return False
        if self.size == 1:
            self.end = None
            self.pre = None
        else:
            self.pre = self.pre.next
        self.size -= 1
        return True
        

    def deleteLast(self) -> bool:
        if self.size == 0:
            return False
        if self.size == 1:
            self.end = None
            self.pre = None
        else:
            self.end = self.end.pre
        self.size -= 1
        return True
        

    def getFront(self) -> int:
        if self.isEmpty():
            return - 1
        return self.pre.val


    def getRear(self) -> int:
        if self.isEmpty():
            return - 1
        return self.end.val
        

    def isEmpty(self) -> bool:
        return self.size == 0
        

    def isFull(self) -> bool:
        return self.size == self.capacity
        


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
