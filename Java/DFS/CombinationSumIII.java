// https://leetcode.com/problems/combination-sum-iii/

class Solution {
    public List<List<Integer>> ret = new ArrayList<>();
    public void dfs(List<Integer> arr, int k, int n) {
        if (k == 0 && n == 0) {
            ret.add(new ArrayList<>(arr));
            return;
        }
        if (k == 0 || n == 0) {
            return;
        }
        
        int start = arr.isEmpty()? 0: arr.get(arr.size() - 1);
        for (int i = start + 1; i < 10 && i <= n; i++) {
            arr.add(i);
            dfs(arr, k - 1, n - i);
            arr.remove(arr.size() - 1);
        }
        return;
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<Integer> arr = new ArrayList<>();
        dfs(arr, k, n);
        return ret;
    }
}
