// https://leetcode.com/problems/range-sum-query-mutable/

class NumArray {
public:
    int n;
    vector<int> nums;
    vector<int> bits;
    NumArray(vector<int>& nums): nums(nums)
    {
        n = nums.size();
        bits.resize(n + 1, 0);
        for (int i = 0; i < n; i ++) {
            int index = i + 1;
            int val = nums[i];
            while (index <= n) {
                bits[index] += val;
                index += (index & -index);
            }
        }
    }

    void update(int index, int val) {
        int diff = val - nums[index];
        int i = index + 1;
        while (i <= n) {
            bits[i] += diff;
            i += (i & -i);
        }    int n;
        nums[index] = val;
    }
    
    
    int presum(int index) {
        int val = 0;
        while (index > 0) {
            val += bits[index];
            index -= (index & -index);
        }
        return val;
    }
    
    
    int sumRange(int left, int right) {
        return presum(right + 1) - presum(left);
    }

};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
