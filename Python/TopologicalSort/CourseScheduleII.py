# https://leetcode.com/problems/course-schedule-ii/

class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        forward = collections.defaultdict(set)
        backward = collections.defaultdict(set)
        for course, pre in prerequisites:
            forward[pre].add(course)
            backward[course].add(pre)
        stack = [i for i in range(numCourses) if not backward[i]]
        order = []
        count = 0
        while stack:
            node = stack.pop()
            count += 1
            order.append(node)
            for i in forward[node]:
                backward[i].remove(node)
                if not backward[i]:
                    stack.append(i)
        return order if count == numCourses else []
