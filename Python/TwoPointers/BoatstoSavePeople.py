# https://leetcode.com/problems/boats-to-save-people/

class Solution:
    def numRescueBoats(self, people: List[int], limit: int) -> int:
        people.sort()
        i, j, ret = 0, len(people) - 1, 0
        while i <= j:
            if i == j:
                ret += 1
                break
            if people[i] + people[j] > limit:
                j -= 1
            else:
                j -= 1
                i += 1
            ret += 1
        return ret
