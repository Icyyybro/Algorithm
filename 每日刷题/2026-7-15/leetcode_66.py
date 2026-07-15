class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        nums = []
        sum = 0

        for i in range(len(digits) - 1, -1, -1):
            if i == len(digits) - 1:
                sum += digits[i] + 1
            else:
                sum += digits[i]
            nums.append(sum % 10)
            sum //= 10
        if sum != 0:
            nums.append(sum)
        
        # reverse
        for i in range(0, len(nums) // 2):
            tmp = nums[i]
            nums[i] = nums[len(nums) - i - 1]
            nums[len(nums) - i - 1] = tmp
        return nums
        