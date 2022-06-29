// https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    void quickSort(vector<int>& V, int from, int to) {
       if (from + 1 >= to) return;
       // choose random pivot:
       int piv = V[from + rand() % (to - from)];
       
       int i = from - 1, j = to;
       while (true) {
          do i++; while (V[i] < piv);
          do j--; while (V[j] > piv);
          if (i >= j) break;
          swap(V[i], V[j]);
       }
       quickSort(V, from, j + 1);
       quickSort(V, j + 1, to);
    }

    vector<int> sortArray(vector<int>& nums) {
      quickSort(nums, 0, nums.size());
      return nums;
    }
};
