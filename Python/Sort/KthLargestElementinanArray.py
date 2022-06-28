# https://leetcode.com/problems/kth-largest-element-in-an-array/

class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        k -= 1
        n = len(nums)
        idx, l, r = self.quickSort(nums, k, 0, n - 1)
        while True:
            if idx > k:
                idx, l, r = self.quickSort(nums, k, l, idx - 1)
            elif idx < k:
                idx, l, r = self.quickSort(nums, k, idx + 1, r)
            else:
                return nums[idx]
    
    
    def quickSort(self, nums, k, left, right):
        l = left
        r = right
        mid = (left + right) // 2
        while l < r:
            
            while l < mid and nums[l] >= nums[mid]:
                l += 1
            if l >= r: 
                break
            nums[l], nums[mid] = nums[mid], nums[l]
            mid = l
            
            while mid < r and nums[r] <= nums[mid]:
                r -= 1
            if l >= r: 
                break
            nums[r], nums[mid] = nums[mid], nums[r]
            mid = r
        return mid, left, right
            
