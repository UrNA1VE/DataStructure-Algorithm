// https://leetcode.com/problems/maximum-points-in-an-archery-competition/

class Solution {
    public int[] maximumBobPoints(int numArrows, int[] aliceArrows) {
        int max = 0, choices = 1<<12, choice = 0;
        for (int i = 1; i <= choices; i++) {
            int curr = 0, spent = 0;
            for (int bit = 0; bit < 12; bit++) {
                if (((i>>bit) & 1) == 1) {
                    spent += aliceArrows[bit] + 1;
                    curr += bit;
                }
            }
            if (curr > max && spent <= numArrows) {
                max = curr;
                choice = i;
            }
        }
        int[] ret = new int[12];
        int remain = numArrows;
        for (int i = 1; i < 12; i++) {
            if (((choice>>i)&1) == 1) {
                ret[i] = aliceArrows[i] + 1;
                remain -= ret[i];
            }
        }
        ret[0] = remain;
        
        
        return ret;
        
    }
}
