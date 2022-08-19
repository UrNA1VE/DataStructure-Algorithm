# https://leetcode.com/problems/split-array-into-consecutive-subsequences/

class Solution:
    def isPossible(self, nums: List[int]) -> bool:
        seq = defaultdict(int)
        cnt = Counter(nums)
        
        for num in nums:
            if not cnt[num]:
                continue
            
            if seq[num - 1]:
                seq[num - 1] -= 1
                seq[num] += 1
            
            else:
                if not cnt[num + 1] or not cnt[num + 2]:
                    return False
                cnt[num + 1] -= 1
                cnt[num + 2] -= 1
                seq[num + 2] += 1
            cnt[num] -= 1
        return True
