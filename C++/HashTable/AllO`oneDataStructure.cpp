// https://leetcode.com/problems/all-oone-data-structure/

class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {
        
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (bucketofkey.find(key) == bucketofkey.cend()) {
            bucketofkey[key] = buckets.insert(buckets.begin(), {0, {key}});
        }
        auto next = bucketofkey[key], curr = next++;
        if (next == buckets.cend() || next->value > curr->value + 1) {
            next = buckets.insert(next, {curr->value + 1, {}});
        }
        next->keys.insert(key);
        bucketofkey[key] = next;
        
        curr->keys.erase(key);
        if (curr->keys.empty()) {
            buckets.erase(curr);
        }
        
        
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (bucketofkey.find(key) == bucketofkey.cend()) return;
        auto prev = bucketofkey[key], curr = prev--;
        bucketofkey.erase(key);
        
        if (curr->value > 1) {
            if (curr == buckets.cbegin() || prev->value < curr->value - 1) {
                prev = buckets.insert(curr, {curr->value - 1, {}});
            }
            prev->keys.insert(key);
            bucketofkey[key] = prev;
        }
        curr->keys.erase(key);
        if (curr->keys.empty()) {
            buckets.erase(curr);
        }
        
        
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
        
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
        
    }
private:
    struct Bucket {
        int value;
        unordered_set<string> keys;
    };
    list<Bucket> buckets;
    unordered_map<string, list<Bucket>::iterator> bucketofkey;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
