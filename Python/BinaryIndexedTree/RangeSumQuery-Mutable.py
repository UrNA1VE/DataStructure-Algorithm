# https://leetcode.com/problems/range-sum-query-mutable/

class NumArray:

    def __init__(self, nums):
        self.nums = nums
        self.arr = [0] + nums

        for i in range(1, len(self.arr)):
            j = i + self.lsb(i)
            if j >= len(self.arr):
                continue

            self.arr[j] += self.arr[i]

    def lsb(self, i):
        return i & (-i)

    def update(self, index, val):
        diff = val - self.nums[index]
        self.nums[index] = val

        index += 1
        while index < len(self.arr):
            self.arr[index] += diff
            index += self.lsb(index)

    def sumRange(self, left, right):
        return self.presum(right + 1) - self.presum(left)

    def presum(self, i):
        prefix = 0
        while i != 0:
            prefix += self.arr[i]
            i -= self.lsb(i)
        return prefix
