# https://leetcode.com/problems/basic-calculator-ii/

class Solution:
    def calculate(self, s: str) -> int:
        dic = {}
        dic['+'] = 1
        dic['-'] = 1
        dic['*'] = 2
        dic['/'] = 2
        dic['#'] = 0
        stackop = []
        stacknum = []
        i = 0
        s = s + '#'
        while i < len(s):
            if s[i] == ' ':
                i += 1
                continue
            elif 48 <= ord(s[i]) <= 57:
                num = 0
                while 48 <= ord(s[i]) <= 57:
                    num = num * 10 + int(s[i])
                    i += 1
                stacknum.append(num)
            elif stackop and dic[stackop[-1]] >= dic[s[i]]:
                if stackop[-1] == '+':
                    num = stacknum[-1] + stacknum[-2]
                    stacknum.pop()
                    stacknum.pop()
                    stacknum.append(num)
                elif stackop[-1] == '-':
                    num = stacknum[-2] - stacknum[-1]
                    stacknum.pop()
                    stacknum.pop()
                    stacknum.append(num)
                elif stackop[-1] == '*':
                    num = stacknum[-1] * stacknum[-2]
                    stacknum.pop()
                    stacknum.pop()
                    stacknum.append(num)
                elif stackop[-1] == '/':
                    num = int(stacknum[-2] / stacknum[-1])
                    stacknum.pop()
                    stacknum.pop()
                    stacknum.append(num)
                stackop.pop()

            else:
                stackop.append(s[i])
                if stackop == ['#']:
                    return stacknum[-1]
                i += 1
