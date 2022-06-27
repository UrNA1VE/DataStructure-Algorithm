# https://leetcode.com/problems/minimum-window-substring/

class Solution:
    def minWindow(self, s: str, t: str) -> str:
        t_count = collections.Counter(t)
        s_count = collections.defaultdict(int)
        match = set()
        sub = collections.deque([])
        answer = ''
        for char in s:
            if char in t_count:
                s_count[char] += 1
                if s_count[char] >= t_count[char]:
                    match.add(char)
            sub.append(char)
            while len(match) == len(t_count):
                if sub[0] in t_count:
                    if s_count[sub[0]] - 1 < t_count[sub[0]]:
                        if not answer or len(answer) > len(sub):
                            answer = ''.join(sub)
                        break
                    else:
                        s_count[sub[0]] -= 1
                        sub.popleft()
                else:
                    sub.popleft()
        return answer
