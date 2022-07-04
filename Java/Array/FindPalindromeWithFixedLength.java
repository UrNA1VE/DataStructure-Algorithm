// https://leetcode.com/problems/find-palindrome-with-fixed-length/

class Solution {
    public long helper(int query, int intLength) {
        int[] curr = new int[intLength];
        int i = 0, j = intLength - 1, tmp = (intLength - 1) / 2;
        curr[i] = 1;
        curr[j] = 1;
        query--;
        
        int k = 1;
        while (tmp > 0) {
            tmp--;
            k *= 10;
            
        }
        
        while (i <= j) {
            int carry = query / k;
            query %= k;
            curr[i] += carry;
            k /= 10;
            if (curr[i] >= 10) {
                return -1;
            }
            if (i < j) {
                curr[j] += carry;
            }
            i++;
            j--;
        }
        
        long ret = 0;
        for (i = 0; i < intLength; i++) {
            ret = ret*10 + curr[i];
        }
        return ret;
        
    }
    
    
    
    public long[] kthPalindrome(int[] queries, int intLength) {
        int n = queries.length;
        long[] ret = new long[n];
        for (int i = 0; i < n; i++) {
            ret[i] = helper(queries[i], intLength);
        }
        return ret;
        
    }
}
