# https://leetcode.com/problems/number-of-excellent-pairs/

class Solution:
    def countExcellentPairs(self, nums: List[int], k: int) -> int:
        nums = set(nums)
        cnt = defaultdict(int)
        for num in nums:
            cnt[bin(num).count("1")] += 1
        ret = 0
        for i in cnt:
            for j in cnt:
                if i + j >= k:
                    ret += cnt[i] * cnt[j]
        return ret
            
        
        
