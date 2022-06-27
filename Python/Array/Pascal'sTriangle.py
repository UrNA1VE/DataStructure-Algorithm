# https://leetcode.com/problems/pascals-triangle/

class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        output = []
        for row in range(numRows):
            res = []
            size = row
            for i in range(size + 1):
                if i == 0 or i == size:
                    res.append(1)
                    continue
                else:
                     res.append(output[row - 1][i - 1] + output[row - 1][i])
            output.append(res)
        return output
        
