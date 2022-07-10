# https://leetcode.com/problems/move-pieces-to-obtain-a-string/

class Solution:
    def canChange(self, start: str, target: str) -> bool:
        n, i, j = len(start), 0, 0
        while i < n or j < n:
            while i < n and start[i] == '_':
                i += 1
            while j < n and target[j] == '_':
                j += 1
            if i == n or j == n:
                if i == j:
                    return True
                return False
            if start[i] != target[j]:
                return False
            if start[i] == target[j] and start[i] == 'L':
                if j > i:
                    return False
            if start[i] == target[j] and start[i] == 'R':
                if j < i:
                    return False
            i += 1
            j += 1
        return True
