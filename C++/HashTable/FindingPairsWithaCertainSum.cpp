// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (int i = 0; i < nums1.size(); i++){
            array1.push_back(nums1[i]);
            if (map1.find(nums1[i]) != map1.end()){
                map1[nums1[i]]++;
            }
            else{
                map1[nums1[i]] = 1;
            }
        }
        for (int i = 0; i < nums2.size(); i++){
            array2.push_back(nums2[i]);
            if (map2.find(nums2[i]) != map2.end()){
                map2[nums2[i]]++;
            }
            else{
                map2[nums2[i]] = 1;
            }
        }
        
    }
    
    void add(int index, int val) {
        int prev = array2[index];
        int now = prev + val;
        array2[index] = now;
        map2[prev]--;
        if (map2.find(now) != map2.end()){
                map2[now]++;
            }
            else{
                map2[now] = 1;
            }
    }
    
    int count(int tot) {
        int res = 0;
        for (auto& x : map1){
            int target = tot - x.first;
            if (map2.find(target) != map2.end()){
                res += map2[target] * x.second;
            }
        }
        return res;
        
    }
private:
    vector<int> array1, array2;
    unordered_map<int, int> map1, map2;
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count
