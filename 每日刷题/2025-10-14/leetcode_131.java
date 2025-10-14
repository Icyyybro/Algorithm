class Solution {
    Boolean[][] dp;
    List<List<String>> ans = new ArrayList<>();
    List<String> list = new ArrayList<>();
    public List<List<String>> partition(String s) {
        int n = s.length();
        init(s);
        dfs(s, 0);
        return ans;
    }

    private void dfs(String s, int start) {
        int n = s.length();
        if(start == n) {
            ans.add(new ArrayList<>(list));
            return;
        }
        for(int end = start; end < n; end++) {
            if(dp[start][end]) {
                list.add(s.substring(start, end + 1));
                dfs(s, end + 1);
                list.remove(list.size() - 1);
            }
        }
    }

    private void init(String s) {
        int n = s.length();
        dp = new Boolean[n][n];
        for(int len = 1; len <= n; len++) {
            for(int start = 0; start < n - len + 1; start++) {
                int end = start + len - 1;
                if(s.charAt(start) != s.charAt(end)) {
                    dp[start][end] = false;
                    continue;
                }
                if(len < 3) {
                    dp[start][end] = true;
                    continue;
                }
                dp[start][end] = dp[start + 1][end - 1];
            }
        }
    }
}