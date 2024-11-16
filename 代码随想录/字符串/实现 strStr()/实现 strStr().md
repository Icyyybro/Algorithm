# 实现 strStr()

# 1. 题目

题目链接：[https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string](https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string "https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string")

实现 strStr() 函数。

给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。

示例 1: 输入: haystack = "hello", needle = "ll" 输出: 2

示例 2: 输入: haystack = "aaaaa", needle = "bba" 输出: -1

说明: 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。

# 2. 算法

此题使用KMP算法，next数组从-1开始，因为我们每次是使用needle\[j+1]的元素和naystack\[i]的元素比较，当不匹配时：j=next\[j]。当j = -1时，其实是用needle\[0]和naystack\[i]比较。

```c++
class Solution {
public:
    int strStr(string haystack, string needle) {
        int ne[100010];
        // 构建next数组
        int j = -1;
        ne[0] = j;
        for(int i = 1; i < needle.size(); i++)
        {
            while(j >= 0 && needle[i] != needle[j + 1])
                j = ne[j];
            if(needle[i] == needle[j + 1])
                j++;
            ne[i] = j;
        }
        // 匹配
        j = -1;
        for(int i = 0; i < haystack.size(); i++)
        {
            while(j >= 0 && haystack[i] != needle[j + 1])
                j = ne[j];
            if(haystack[i] == needle[j + 1])
                j++;
            //判断是否匹配成功
            if(j == needle.size() - 1)
                return i - needle.size() + 1;
        }
        return -1;
    }
};
```
