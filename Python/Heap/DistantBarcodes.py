# https://leetcode.com/problems/distant-barcodes/

class Solution:
    def rearrangeBarcodes(self, barcodes: List[int]) -> List[int]:
        count = collections.Counter(barcodes)
        stack = []
        for i in count:
            stack.append((-count[i], i))
        heapq.heapify(stack)
        pre_count = 0
        pre_code = 0
        res = []
        while stack:
            count, code = heapq.heappop(stack)
            res.append(code)
            if pre_count:
                heapq.heappush(stack, (pre_count, pre_code))
            pre_code = code
            pre_count = count + 1
        return res
