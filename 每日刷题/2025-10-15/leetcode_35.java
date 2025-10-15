class Solution {
    public int searchInsert(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n - 1;
        int ans = n;
        while(left <= right) {
            int mid = (left + right) >> 1;
            if(nums[mid] < target) {
                left = mid + 1;
            }
            else if(nums[mid] > target) {
                right = mid - 1;
                ans = mid;
            } 
            else {
                ans = mid;
                break;
            }   
        }
        return ans;
    }
}