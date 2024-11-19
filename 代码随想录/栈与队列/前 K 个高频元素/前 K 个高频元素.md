# 前 K 个高频元素

# 1. 题目

题目链接：[https://leetcode.cn/problems/top-k-frequent-elements](https://leetcode.cn/problems/top-k-frequent-elements "https://leetcode.cn/problems/top-k-frequent-elements")

给定一个非空的整数数组，返回其中出现频率前 k 高的元素。

示例 1:

- 输入: nums = \[1,1,1,2,2,3], k = 2
- 输出: \[1,2]

示例 2:

- 输入: nums = \[1], k = 1
- 输出: \[1]

提示：

- 你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
- 你的算法的时间复杂度必须优于 $O(n \log n)$ , n 是数组的大小。
- 题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
- 你可以按任意顺序返回答案。

# 2. 算法

定义一个哈希表和一个优先级队列（大顶堆），哈希表第一个元素为数字，第二个元素为出现次数。

优先级队列按照出现次数排序。

```c++
class Solution {
public:
    //小顶堆
    class mycomparison {
    public:
        bool operator()(pair<int, int> lhs, pair<int, int> rhs) {
            return lhs.second < rhs.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> hash;       //第一个元素为数字，第二个元素为频率
        for(int i = 0; i < nums.size(); i++)
            hash[nums[i]]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
        for (auto it = hash.begin(); it != hash.end(); it++)
            pri_que.push(*it);
        while(k--)
        {
            ans.push_back(pri_que.top().first);
            pri_que.pop();
        }
        return ans;
    }
};
```

priority\_queue用法详见：

[priority\_queue](../../../补充知识/priority_queue/priority_queue.md "priority_queue")
