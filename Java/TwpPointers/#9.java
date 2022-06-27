// Given an integer x, return true if x is palindrome integer.

// An integer is a palindrome when it reads the same backward as forward.

// For example, 121 is a palindrome while 123 is not.

// Input: x = 121
// Output: true
// Explanation: 121 reads as 121 from left to right and from right to left.

class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) return false;
        char[] arr = ("" + x).toCharArray();
        int j = arr.length - 1, i = 0;
        while (i < j) {
            if (arr[i++] != arr[j--]) return false;
        }
        return true;
        
        
    }
}
