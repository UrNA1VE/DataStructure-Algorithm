# https://leetcode.com/problems/4sum/

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        two_dict = {}
        res_dict = {}
        result = []
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                a = nums[i]
                b = nums[j]
                candidate = two_dict.get(target - a - b)
                if candidate is not None:
                    for each in candidate:
                        m, n, p, q = each
                        if len(set([p, q, i, j])) == 4:
                            res = [a, b, m, n]
                            res.sort()
                            if tuple(res) not in res_dict:
                                result.append(res)
                                res_dict[tuple(res)] = 1
                if a + b not in two_dict:
                    two_dict[a + b] = [(a, b, i, j)]
                else:
                    two_dict[a + b].append((a, b, i, j))
        return result
