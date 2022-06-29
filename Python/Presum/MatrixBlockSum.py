# https://leetcode.com/problems/matrix-block-sum/ 

class Solution:
    def matrixBlockSum(self, mat: List[List[int]], k: int) -> List[List[int]]:
        m, n = len(mat), len(mat[0])
        presum = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        ret = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m):
            for j in range(n):
                if i == 0 and j == 0:
                    presum[i + 1][j + 1] = mat[i][j]
                elif i == 0:
                    presum[i + 1][j + 1] = presum[i + 1][j] + mat[i][j]
                elif j == 0:
                    presum[i + 1][j + 1] = presum[i][j + 1] + mat[i][j]
                else:
                    presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] - presum[i][j] + mat[i][j]
        for i in range(1, m + 1):
            for j in range(1, n + 1):
                li, lj, ri, rj = max(0, i - k - 1), max(0, j - k - 1), min(m, i + k), min(n, j + k)
                ret[i - 1][j - 1] = presum[ri][rj]  - presum[ri][lj] - presum[li][rj] + presum[li][lj]


                
        return ret
        
