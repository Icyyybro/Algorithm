# 子集II

# 1. 题目

题目链接：[https://leetcode.cn/problems/subsets-ii](https://leetcode.cn/problems/subsets-ii "https://leetcode.cn/problems/subsets-ii")

给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

- 输入: \[1,2,2]
- 输出: \[ \[2], \[1], \[1,2,2], \[2,2], \[1,2], \[] ]

# 2. 算法

和之前的方法一样，需要剪枝。

[组合总和II](../组合总和II/组合总和II.md "组合总和II")

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        if(nums.empty())
        {
            ans.push_back(path);
            return ans;
        }
        sort(nums.begin(), nums.end());
        backTracing(nums, 0, used);
        return ans;
    }

    void backTracing(vector<int> nums, int startIndex, vector<bool> used)
    {
        ans.push_back(path);
        for(int i = startIndex; i < nums.size(); i++)
        {
            if(i > 0 && used[i - 1] == false && nums[i] == nums[i - 1])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backTracing(nums, i + 1, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
```
