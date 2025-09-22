class Solution {
    List<List<String>> ans = new ArrayList<>();
    List<String> list = new ArrayList<>();
    boolean[][] dp;

    public List<List<String>> partition(String s) {
        init(s);
        dfs(s, 0);
        return ans;
    }

    private void init(String s) {
        int n = s.length();
        dp = new boolean[n][n];
        for(int len = 1; len <= n; len++) {
            for(int start = 0; start < n - len + 1; start++) {
                int end = start + len - 1;
                if(s.charAt(start) != s.charAt(end))
                    continue;
                if(len <= 3)
                    dp[start][end] = true;
                else {
                    dp[start][end] = dp[start + 1][end - 1];
                }
            }
        }
    }

    private void dfs(String s, int idx) {
        if(s.length() == idx) {
            ans.add(new ArrayList(list));
            return;
        }
        for(int i = idx; i < s.length(); i++) {
            if(dp[idx][i]) {
                list.add(s.substring(idx, i + 1));
                dfs(s, i + 1);
                list.remove(list.size() - 1);
            }
        }
    }
}