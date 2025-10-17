class Solution {
    public List<Integer> partitionLabels(String s) {
        List<Integer> ans = new ArrayList<>();
        int n = s.length();
        int[] end = new int[26];

        for(int i = 0; i < n; i++) {
            char c = s.charAt(i);
            end[c - 'a'] = i;
        }

        int left = 0;
        int idx = 0;
        for(int i = 0; i < n; i++) {
            char c = s.charAt(i);
            idx = Math.max(idx, end[c - 'a']);
            if(idx == i) {
                ans.add(i - left + 1);
                left = i + 1;
            }
        }
        return ans;
    }
}