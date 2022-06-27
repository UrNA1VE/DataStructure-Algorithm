// https://leetcode.com/problems/permutations-ii/

class Solution {
    List<List<Integer>> ret;
    
    public String helper(List<Integer> arr) {
        String res = "";
        for (int x: arr) {
            res += Integer.toString(x);
            res += "#";
        }
        return res;
    }
    
    public void dfs(int[] nums, List<Integer> arr, boolean[] visit, Set<String> exist) {
        if (visit.length == arr.size()) {
            String curr = helper(arr);
            if (!exist.contains(curr)) {
                ret.add(new ArrayList<Integer>(arr));
                exist.add(curr);
            }
            
            return;
        }
        for (int i = 0; i < nums.length; i++) {
            if (!visit[i]) {
                visit[i] = true;
                arr.add(nums[i]);
                dfs(nums, arr, visit, exist);
                arr.remove(arr.size() - 1);
                visit[i] = false;
            }
        }
        return;
    }
    
    public List<List<Integer>> permuteUnique(int[] nums) {
        ret = new ArrayList<>();
        Set<String> exist = new HashSet<String>();
        List<Integer> arr = new ArrayList<>();
        int n = nums.length;
        boolean[] visit = new boolean[n];
        dfs(nums, arr, visit, exist);
        return ret;
    }
}
