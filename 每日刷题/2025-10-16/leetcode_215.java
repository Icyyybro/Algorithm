class Solution {
    public int findKthLargest(int[] nums, int k) {
        int n = nums.length;
        Heap(nums, n);
        int ans = 0;
        while(k-- != 0) {
            ans = nums[0];
            nums[0] = nums[n - 1];
            n--;
            downHeap(nums, n, 0);
            System.out.println(ans);
        }
        return ans;
    }

    private void downHeap(int[] nums, int size, int idx) {
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;
        int target = idx;
        if(left < size && nums[target] < nums[left]) {
            target = left;
        }
        if(right < size && nums[target] < nums[right]) {
            target = right;
        }
        if(target == idx)
            return;
        int temp = nums[target];
        nums[target] = nums[idx];
        nums[idx] = temp;
        downHeap(nums, size, target);
    }

    private void Heap(int[] nums, int size) {
        for(int i = size / 2 - 1; i >= 0; i--) {
            downHeap(nums, size, i);
        }
    }
}