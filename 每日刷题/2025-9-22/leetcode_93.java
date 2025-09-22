class Solution {
    List<String> ans = new ArrayList<>();
    List<Integer> list = new ArrayList<>();
    boolean[][] isLegal;

    public List<String> restoreIpAddresses(String s) {
        init(s);
        dfs(s, 0);
        return ans;
    }

    private void dfs(String s, int idx) {
        int n = s.length();
        if(list.size() == 4 && idx == n) {
            // System.out.println("success");
            getString(s);
            return;
        }
        for(int i = idx; i < s.length() && i < idx + 3; i++) {
            if(isLegal[idx][i]) {
                list.add(i);
                dfs(s, i + 1);
                list.remove(list.size() - 1);
            }
        }
    }

    private void getString(String s) {
        StringBuilder sb = new StringBuilder();
        int start = 0;
        for(int i = 0; i < list.size(); i++) {
            sb.append(s.substring(start, list.get(i) + 1));
            start = list.get(i) + 1;
            if(i != list.size() - 1)
                sb.append('.');
        }
        ans.add(sb.toString());
    }

    private void init(String s) {
        int n = s.length();
        isLegal = new boolean[n][n];
        for(int start = 0; start < n; start++) {
            for(int end = start; end < start + 3 && end < n; end++) {
                isLegal[start][end] = judge(s, start, end);
            }
        }
    }

    private boolean judge(String s, int start, int end) {
        if(s.charAt(start) == '0' && start != end)
            return false;
        int sum = 0;
        for(int i = start; i <= end; i++) {
            sum *= 10;
            sum += s.charAt(i) - '0';
        }
        if(sum > 255)
            return false;
        else {
            // System.out.println(start + ":" + end);
            return true;
        }
            
    }
}