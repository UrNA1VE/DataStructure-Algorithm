// https://leetcode.com/problems/longest-turbulent-subarray/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;
        int up = 1, down = 1, i = 1, j = 1, resup = 1, resdown = 1;
        
        
        while (i < n) {
            if (arr[i] > arr[i - 1]) {
                up++;
                down = 1;
            }
            else if (arr[i] < arr[i - 1]) {
                down++;
                up = 1;
            }
            else {
                down = 1;
                up = 1;
            }
            resup = max(resup, up);
            resdown = max(resdown, down);
            int tmp = down;
            down = up;
            up = tmp;
            i++;
            
        }

        return max(resup, resdown);
    }
};
