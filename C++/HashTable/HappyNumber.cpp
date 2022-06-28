// https://leetcode.com/problems/happy-number/

class Solution {
public:
    unordered_set<int> table;
    bool isHappy(int n) {
        if (n == 1){
            return true;
        }else{
            int sum = sumSD(n);
            if (table.find(sum) != table.end()){
                return false;
            }
            table.insert(sum);
            return isHappy(sum);
        }
        
    }
    int sumSD(int num){
        return num == 0? 0 : pow(num % 10, 2) + sumSD(num / 10);
    }
};
