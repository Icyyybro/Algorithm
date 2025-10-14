class Solution {
    List<String> ans = new ArrayList<>();
    StringBuilder sb = new StringBuilder();
    public List<String> generateParenthesis(int n) {
        dfs(0, 0, n);
        return ans;
    }

    private void dfs(int left, int right, int n) {
        if(left == n && right == n) {
            ans.add(sb.toString());
            return;
        }
        if(left < n) {
            sb.append('(');
            left++;
            dfs(left, right, n);
            left--;
            sb.deleteCharAt(sb.length() - 1);
        }
        if(right < left) {
            sb.append(')');
            right++;
            dfs(left, right, n);
            right--;
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}