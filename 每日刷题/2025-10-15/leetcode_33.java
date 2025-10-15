class Solution {
    public int search(int[] nums, int target) {
        int n = nums.length;
        int left = 0;
        int right = n - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(nums[mid] == target)
                return mid;
            //左边有序
            if(nums[left] <= nums[mid]) {
                //在左边
                if(target >= nums[left] && target < nums[mid]) {
                    right = mid - 1;
                }
                //在右边
                else {
                    left = mid + 1;
                }
            }
            //右边有序
            else {
                //在右边
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                }
                //在左边
                else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
}