# https://leetcode.com/problems/permutations-ii/

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        output = []
        n = len(nums)
        visited = set()

        def backtrack(i):
            if tuple(nums) in visited:
                return
            if i >= n:
                output.append(nums[:])
                visited.add(tuple(nums))
                return
            else:
                for j in range(i, n):
                    nums[i], nums[j] = nums[j], nums[i]
                    backtrack(i + 1)
                    nums[i], nums[j] = nums[j], nums[i]
                return
        backtrack(0)
        return output
