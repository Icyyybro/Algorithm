# 组合总和III

# 1. 题目

题目链接：[https://leetcode.cn/problems/combination-sum-iii](https://leetcode.cn/problems/combination-sum-iii "https://leetcode.cn/problems/combination-sum-iii")

找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

- 所有数字都是正整数。
- 解集不能包含重复的组合。

示例 1: 输入: k = 3, n = 7 输出: \[\[1,2,4]]

示例 2: 输入: k = 3, n = 9 输出: \[\[1,2,6], \[1,3,5], \[2,3,4]]

# 2. 算法

本题注意要满足两个条件。

```c++
class Solution {
public:
vector<vector<int>> ans;
vector<int> path;
    vector<vector<int>> combinationSum3(int k, int n) {
        backTracing(k, n, 1);
        return ans;
    }

    void backTracing(int k, int n, int startIndex)
    {
        if(path.size() == k)
        {
            if(sumPath() == n)
                ans.push_back(path);
            return;
        }
        for(int i = startIndex; i <= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backTracing(k, n, i + 1);
            path.pop_back();
        }
    }

    int sumPath()
    {
        int sum = 0;
        for(int i = 0; i < path.size(); i++)
            sum += path[i];
        return sum;
    }
};
```
