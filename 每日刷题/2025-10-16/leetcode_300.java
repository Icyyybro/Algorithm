class Solution {
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n + 1];
        int cnt;

        dp[0] = nums[0];
        cnt = 1;
        for(int i = 1; i < n; i++) {
            // 最大
            if(dp[cnt - 1] < nums[i]) {
                dp[cnt] = nums[i];
                cnt++;
                continue;
            }
            // 二分查找第一个比它大的
            int left = 0;
            int right = cnt;
            int idx = cnt;
            int target = nums[i];
            while(left <= right) {
                int mid = (left + right) / 2;
                if(dp[mid] == target) {
                    idx = mid;
                    break;
                }
                else if(dp[mid] < target) {
                    left = mid + 1;
                }
                else {
                    idx = mid;
                    right = mid - 1;
                }
            }
            dp[idx] = target;
        }
        return cnt;
    }
}