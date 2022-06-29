# https://leetcode.com/problems/minimum-jumps-to-reach-home/

class Solution:
    def minimumJumps(self, forbidden: List[int], a: int, b: int, x: int) -> int:
        queue=deque([[0,1]])
        level=0
        visited=set()
        visited.add((0,1))
        furthest =max(x, max(forbidden)) + a + b
        for values in forbidden:
            visited.add((values,1))
            visited.add((values,-1))
        
        while len(queue)>0:
            size=len(queue)
            
            
            for i in range(size):
                index,dir=queue.popleft()
                
                if index==x:
                    return level

                
                if dir==1:
                    if index+a<=furthest and (index+a,1) not in visited:
                        visited.add((index+a,1))
                        queue.append([index+a,1])
                    if index-b>0 and (index-b,-1) not in visited:
                        visited.add((index-b,-1))
                        queue.append([index-b,-1])
                        
                elif dir==-1:
                    if index+a<=furthest and (index+a,1) not in visited:
                        visited.add((index+a,1))
                        queue.append([index+a,1])
                    
            level+=1

        return -1
