# 全排列 II

# 1. 题目

题目链接：[https://leetcode.cn/problems/permutations-ii](https://leetcode.cn/problems/permutations-ii "https://leetcode.cn/problems/permutations-ii")

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

- 输入：nums = \[1,1,2]
- 输出： \[\[1,1,2], \[1,2,1], \[2,1,1]]

示例 2：

- 输入：nums = \[1,2,3]
- 输出：\[\[1,2,3],\[1,3,2],\[2,1,3],\[2,3,1],\[3,1,2],\[3,2,1]]

提示：

- 1 <= nums.length <= 8
- -10 <= nums\[i] <= 10

# 2. 算法

## 2.1 visited + 哈希表

这个题目需要有两个限制：

首先，题目要求找到任意顺序的全排列，所以要维护一个visited数组记录当前元素是否被访问过。

其次，题目说明nums中可能存在重复元素，这时候我们就需要设置一个哈希表，存储当前层已经访问过的数值。

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        if(nums.empty())
            return ans;
        backTracing(nums, visited);
        return ans;
    }

    void backTracing(vector<int> nums, vector<bool>& visited)
    {
        if(nums.size() == path.size())
        {
            ans.push_back(path);
            return;
        }
        unordered_set<int> map;
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i] == false && map.find(nums[i]) == map.end())
            {
                path.push_back(nums[i]);
                visited[i] = true;
                map.insert(nums[i]);
                backTracing(nums, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};
```

## 2.2 visited + 兄弟节点判断

由于这道题目不需要返回数组下标，所以我们可以先排序，将重复的元素放到一起，这样我们只需要比较同一层的左兄弟节点的值是否等于当前节点的值即可。然后再判断当前元素是否已经在路径里。

```c++
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        if(nums.empty())
            return ans;
        sort(nums.begin(), nums.end());
        backTracing(nums, visited);
        return ans;
    }

    void backTracing(vector<int> nums, vector<bool>& visited)
    {
        if(nums.size() == path.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && visited[i - 1] == false && nums[i] == nums[i - 1])
                continue;

            if(visited[i] == false)
            {
                path.push_back(nums[i]);
                visited[i] = true;
                backTracing(nums, visited);
                path.pop_back();
                visited[i] = false;
            }
        }
    }
};
```
