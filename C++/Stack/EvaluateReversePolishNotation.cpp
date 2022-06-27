// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        int sign = 1, curr, i, n, num1, num2;
        for (auto x: tokens) {
            i = 0;
            n = x.length();
            curr = 0;
            if ((x[0] >= '0' && x[0] <= '9') || (x[0] == '-' && x.length() > 1)) {
                if (x[i] == '-') {
                    sign = -1;
                    i++;
                }
                for (; i < n; i++) {
                    curr = curr * 10 + (x[i] - '0');
                }
                nums.push_back(curr * sign);
                sign = 1;
            }
            else {
                num2 = nums.back();
                nums.pop_back();
                num1 = nums.back();
                nums.pop_back();
                if (x == "-") {
                    nums.push_back(num1 - num2);
                }
                else if (x == "+") {
                    nums.push_back(num1 + num2);
                }
                else if (x == "*") {
                    nums.push_back(num1 * num2);
                }
                else if (x == "/") {
                    nums.push_back(num1 / num2);
                }
                
            }
            
        }
        return nums.back();
        
    }
};
