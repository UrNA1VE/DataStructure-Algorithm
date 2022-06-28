// https://leetcode.com/problems/insert-delete-getrandom-o1/

class RandomizedSet {
public:
    vector<int> v;
    unordered_map<int, int> table;
    int last = -1;
    
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (table.count(val)) {
            return false;
        }
        last++;
        table[val] = last;
        v.emplace_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (!table.count(val)) return false;
        int position = table[val];
        table[v[last]] = position;
        swap(v[last], v[position]);
        
        last--;
        v.pop_back();
        table.erase(val);
        return true;
    }
    
    int getRandom() {
        int index = rand() % (last + 1);
        return v[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
