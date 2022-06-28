# https://leetcode.com/problems/expression-add-operators/



class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        def dfs(pos, cur, pre, exp):

            if pos == n:
                if cur == target:
                    res.append(exp)
                return
        
            for right in range(pos + 1, n + 1):
                tmp = num[pos:right]
                if tmp[0] == '0' and len(tmp) > 1:
                    break
                    
                val = int(tmp)
                if pos == 0:
                    dfs(right, val, val, tmp)
                else:
                    dfs(right, cur + val, val, exp + "+" + tmp)
                    dfs(right, cur - val, -val, exp + "-" + tmp)
                    dfs(right, cur - pre + pre * val, pre * val, exp + "*" + tmp)
            
        
        res = list()
        if not num or len(num) == 0:
            return res
        n = len(num)
        dfs(0, 0, 0, "")
        return res
        
        
