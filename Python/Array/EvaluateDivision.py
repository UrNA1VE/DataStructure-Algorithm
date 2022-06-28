# https://leetcode.com/problems/evaluate-division/

class Solution:
    def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
        quot = collections.defaultdict(dict)
        for (num, den), val in zip(equations, values):
            quot[num][num] = quot[den][den] = 1.0
            quot[num][den] = val
            quot[den][num] = 1 / val
        for k in quot:
            for i in quot[k]:
                for j in quot[k]:
                    quot[i][j] = quot[i][k] * quot[k][j]
        return [quot[num].get(den, -1.0) for num, den in queries]
