class Solution {
    public int maxProfit(int[] prices) {
        int ans = 0;
        int n = prices.length;
        int lowestPrice = prices[0];

        for(int i = 0; i < n; i++) {
            lowestPrice = Math.min(lowestPrice, prices[i]);
            ans = Math.max(ans, prices[i] - lowestPrice);
        }
        return ans;
    }
}