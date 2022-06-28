// https://leetcode.com/problems/contains-duplicate/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() > 1){
           unordered_set<int> unset;
           pair<unordered_set<int>::iterator,bool> res;
            for(int i = 0; i <nums.size(); ++i)
            {
                res = unset.insert(nums[i]);
                if(res.second==false)
                    return true;
            }  
       }
        return false;
    }
};
