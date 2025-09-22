class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    int sum = 0;

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        dfs(candidates, 0, target);
        return ans;
    }

    private void dfs(int[] candidates, int idx, int target) {
        if(target == sum) {
            ans.add(new ArrayList(list));
            return;
        }

        for(int i = idx; i < candidates.length; i++) {
            if(sum + candidates[i] > target)
                break;
            list.add(candidates[i]);
            sum += candidates[i];
            dfs(candidates, i, target);
            list.remove(list.size() - 1);
            sum -= candidates[i];
        }
    }
}