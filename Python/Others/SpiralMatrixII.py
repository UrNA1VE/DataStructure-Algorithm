# https://leetcode.com/problems/spiral-matrix-ii/
class Solution:
    def generateMatrix(self, n: int) -> List[List[int]]:
        if n == 0:
            return [[]]
        if n == 1:
            return [[1]]
        res = [[0] * n for i in range(n)]
        num = 0
        times = 1
        location = [0, 0]
        direction = [0, 1]
        while num < n ** 2:
            if n % 2 == 1 and n - times == 0:
                res[n // 2][n // 2] = num + 1
                break
            if direction == [0, 1] and num < n ** 2:
                i = location[0]
                j = location[1]
                for k in range(n - times):
                    num += 1
                    res[i][j + k] = num
                location = [i, j + k + 1]
                direction = [1, 0]

            elif direction == [1, 0] and num < n ** 2:
                i = location[0]
                j = location[1]
                for k in range(n - times):
                    num += 1
                    res[i + k][j] = num
                location = [i + k + 1, j]
                direction = [0, -1]

            elif direction == [0, -1] and num < n ** 2:
                i = location[0]
                j = location[1]
                for k in range(n - times):
                    num += 1
                    res[i][j - k] = num
                location = [i, j - k - 1]
                direction = [-1, 0]


            elif direction == [-1, 0] and num < n ** 2:
                i = location[0]
                j = location[1]
                for k in range(n - times):
                    num += 1
                    res[i - k][j] = num
                location = [i - k , j + 1]
                direction = [0, 1]
                times += 2
        return res
