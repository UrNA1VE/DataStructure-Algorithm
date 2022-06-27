# https://leetcode.com/problems/word-break/

class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        if not s or not wordDict:
            return False
        queue = deque([''])
        lens_found = defaultdict(set)
        while queue:
            prefix = queue.popleft()
            for word in wordDict:
                new_prefix = prefix + word
                if new_prefix == s:
                    return True
                elif len(new_prefix) in lens_found:
                    continue
                elif s.startswith(new_prefix):
                    queue.append(new_prefix)
                    lens_found[len(new_prefix)] = 1
        return False
