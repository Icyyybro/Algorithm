class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> ans = new ArrayList<>();
        int[] cntS = new int[26];
        int[] cntP = new int[26];
        int sLen = s.length();
        int pLen = p.length();

        for(int i = 0; i < pLen; i++) {
            char c = p.charAt(i);
            cntP[c - 'a']++;
        }

        for(int i = 0; i < sLen; i++) {
            char c = s.charAt(i);
            cntS[c - 'a']++;
            if(i >= pLen)
                cntS[s.charAt(i - pLen) - 'a']--;
            if(Arrays.equals(cntS, cntP))
                ans.add(i - pLen + 1);
        }
        return ans;
    }
}