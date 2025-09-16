class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    private void dfs(int n, int k, int start) {
        if(list.size() == k) {
            ans.add(new ArrayList(list));
            return;
        }
        for(int i = start; i <= n; i++) {
            list.add(i);
            dfs(n, k, i + 1);
            list.remove(list.size() - 1);
        }
    }
}

// 剪枝
class Solution {
    List<List<Integer>> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k) {
        dfs(n, k, 1);
        return ans;
    }

    private void dfs(int n, int k, int start) {
        if(list.size() == k) {
            ans.add(new ArrayList(list));
            return;
        }
        for(int i = start; i <= n; i++) {
            if(n - i + 1 < k - list.size())
                return;
            list.add(i);
            dfs(n, k, i + 1);
            list.remove(list.size() - 1);
        }
    }
}