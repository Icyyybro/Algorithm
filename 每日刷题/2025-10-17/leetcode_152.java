class Solution {
    public int maxProduct(int[] nums) {
        int ans = nums[0];
        int n = nums.length;
        int[] max = new int[n];
        int[] min = new int[n];

        max[0] = nums[0];
        min[0] = nums[0];
        for(int i = 1; i < n; i++) {
            max[i] = Math.max(Math.max(max[i - 1] * nums[i], min[i - 1] * nums[i]), nums[i]);
            min[i] = Math.min(Math.min(max[i - 1] * nums[i], min[i - 1] * nums[i]), nums[i]);
            ans = Math.max(ans, max[i]);
        }
        return ans;
    }
}