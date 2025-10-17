class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        int sLen = s.length();
        boolean[] dp = new boolean[sLen + 1];
        wordDict.sort(new Comparator<String>(){
            @Override
            public int compare(String s1, String s2) {
                return s1.length() - s2.length();
            }
        });

        dp[0] = true;
        for(int i = 1; i <= sLen; i++) {
            for(int j = 0; j < wordDict.size(); j++) {
                String str = wordDict.get(j);
                if(str.length() > i)
                    break;
                if(str.equals(s.substring(i - str.length(), i)))
                    dp[i] = dp[i - str.length()];
                if(dp[i] == true)
                    break;
            }
        }
        return dp[sLen];
    }
}