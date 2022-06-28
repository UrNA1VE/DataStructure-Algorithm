# https://leetcode.com/problems/different-ways-to-add-parentheses/

class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        dp = {}
        def helper(exp):
            if exp in dp:
                return dp[exp]
            if exp.isdigit():
                dp[exp] = [int(exp)]
                return dp[exp]
            else:
                res = []
                for i in range(1, len(exp)):
                    if exp[i] in ['*', '+', '-']:
                        left = helper(exp[:i])
                        right = helper(exp[i + 1:])
                        for l in left:
                            for r in right:
                                if exp[i] == '+':
                                    res += [l + r]
                                elif exp[i] == '-':
                                    res += [l - r]
                                elif exp[i] == '*':
                                    res += [l * r]
                        dp[exp] = res
                return dp[exp]
        return helper(input)
