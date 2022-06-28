# https://leetcode.com/problems/patching-array/ 

class Solution:
    def minPatches(self, nums: List[int], n: int) -> int:
        index = res = allsum = 0
        length = len(nums)
        while allsum < n:
            if index < length:
                if nums[index] > allsum + 1:
                    allsum += allsum + 1 
                    res += 1
                else:
                    allsum += nums[index]
                    index += 1
            else:
                allsum += allsum + 1
                res += 1
        return res
        
