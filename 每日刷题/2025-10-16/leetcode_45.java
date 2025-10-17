class Solution {
    public int jump(int[] nums) {
        int ans = 0;
        int range = 0;
        int nextRange = nums[0];
        int n = nums.length;

        for(int i = 0; i < n; i++) {
            if(i > range) {
                range = nextRange;
                nextRange = 0;
                ans++;
            }
            nextRange = Math.max(nextRange, nums[i] + i);
        }
        return ans;
    }
}