// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/

class Solution {
public:
    int minimumBuckets(string street) {
        int n = street.length();
        if (street == "H") return -1;
        if (street == ".") return 0;
        if (street.substr(0, 2) == "HH") return -1;
        if (street.substr(n - 2, 2) == "HH") return -1;
        for (int i = 0; i < n - 2; i++) {
            if (street.substr(i, 3) == "HHH") return -1;
        } 
        int countH = 0;
        for (char c:street) {
            if (c == 'H') countH++;
        }
        
        int i = 0;
        while (i < n - 2) {
            if (street.substr(i, 3) == "H.H") {
                countH--;
                i += 2;
            }
            i += 1;
        }
        return countH;
        
        
    }
};
