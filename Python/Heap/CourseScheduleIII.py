# https://leetcode.com/problems/course-schedule-iii/

class Solution:
    def scheduleCourse(self, courses: List[List[int]]) -> int:
        pq = []
        courses.sort(key = lambda course: course[1])
        curr = 0
        for duration, end in courses:
            curr += duration
            heapq.heappush(pq, -duration)
            while curr > end:
                curr += heapq.heappop(pq)
        return len(pq)
        
