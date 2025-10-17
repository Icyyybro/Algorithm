class Solution {
    public boolean canPartition(int[] nums) {
        int n = nums.length;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        int target = sum / 2;
        if(target * 2 != sum)
            return false;

        int[] dp = new int[target + 1];
        
        for(int j = 0; j < n; j++)
            for(int i = target; i >= nums[j]; i--) {
                dp[i] = Math.max(dp[i - nums[j]] + nums[j], dp[i]);
            }
        return dp[target] == target;
    }
}