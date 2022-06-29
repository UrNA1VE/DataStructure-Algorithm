// https://leetcode.com/problems/create-sorted-array-through-instructions/

class BIT{
private:
    int* tree;
    int size;
public:
    BIT(int s): size(s){
        tree = new int[size];
        fill_n(tree, size, 0);
    }
    
    void update(int i) {
        for (; i < size; i += i&-i) {
            tree[i] += 1;
        }
    }
    int get(int i) {
        int sum = 0;
        for (; i > 0; i -= i&-i) {
            sum += tree[i];
        }
        return sum;
    }
};

class Solution {
public:
    int createSortedArray(vector<int>& instructions) {
        BIT bit(*max_element(instructions.begin(), instructions.end()) + 1);
        int mod = 1e9+7, n = instructions.size(), cost = 0;
        for (int i = 0; i < n; i++) {
            cost += min(bit.get(instructions[i] - 1), i - bit.get(instructions[i]));
            cost %= mod;
            bit.update(instructions[i]);
        }
        return cost;
    }
};
