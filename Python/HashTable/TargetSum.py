# https://leetcode.com/problems/target-sum/

from collections import defaultdict
import copy
class Solution:
    def findTargetSumWays(self, nums, S: int) -> int:
        if not nums:
            return 0
        pre = defaultdict(int)
        pre[nums[0]] += 1
        pre[-nums[0]] += 1
        for i in range(1, len(nums)):
            dic = defaultdict(int)
            for j in pre.keys():
                dic[j + nums[i]] += pre[j]
                dic[j - nums[i]] += pre[j]
            pre = copy.deepcopy(dic)
        return pre[S]
