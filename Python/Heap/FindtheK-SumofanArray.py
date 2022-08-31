# https://leetcode.com/problems/find-the-k-sum-of-an-array/

class Solution:
    def kSum(self, nums: List[int], k: int) -> int:
        MAX = sum(max(0, num) for num in nums)
        nums = sorted(abs(num) for num in nums)
        cnt = 1
        hp = [(-MAX + nums[0], 0)]
        ret = MAX
        n = len(nums)
        while cnt < k:
            curr, i = heapq.heappop(hp)
            ret = -curr
            cnt += 1
            if i + 1 < n:
                heapq.heappush(hp, (curr - nums[i] + nums[i + 1], i + 1))
                heapq.heappush(hp, (curr + nums[i + 1], i + 1))
        return ret


            
        
