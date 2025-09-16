class Solution {
    List<String> ans = new ArrayList<>();
    List<String> list = new ArrayList<>();
    StringBuilder sb = new StringBuilder();

    private void init() {
        list.add("");
        list.add("");
        list.add("abc");
        list.add("def");
        list.add("ghi");
        list.add("jkl");
        list.add("mno");
        list.add("pqrs");
        list.add("tuv");
        list.add("wxyz");
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0)
            return ans;
        init();
        dfs(digits, 0);
        return ans;
    }

    private void dfs(String digits, int idx) {
        if(idx == digits.length()) {
            ans.add(sb.toString());
            return;
        }
        int num = digits.charAt(idx) - '0';
        String letters = list.get(num);
        for(int i = 0; i < letters.length(); i++) {
            sb.append(letters.charAt(i));
            dfs(digits, idx + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}