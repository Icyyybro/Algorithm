class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    int sum = 0;

    public List<List<Integer>> combinationSum3(int k, int n) {
        dfs(k, n, 1);
        return ans;
    }

    private void dfs(int k, int n, int start) {
        if(sum == n && list.size() == k) {
            ans.add(new ArrayList(list));
            return;
        }
        for(int i = start; i <= 9; i++) {
            if(list.size() >= k || sum + i > n)
                return;
            list.add(i);
            sum += i;
            dfs(k, n, i + 1);
            list.remove(list.size() - 1);
            sum -= i;
        }
    }
}