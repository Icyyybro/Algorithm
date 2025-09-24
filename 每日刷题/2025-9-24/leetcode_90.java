class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        dfs(nums, 0);
        return ans;
    }

    private void dfs(int[] nums, int start) {
        int n = nums.length;
        ans.add(new ArrayList(list));
        for(int i = start; i < n; i++) {
            if(i > start && nums[i] == nums[i - 1])
                continue;
            list.add(nums[i]);
            dfs(nums, i + 1);
            list.remove(list.size() - 1);
        }
    }
}