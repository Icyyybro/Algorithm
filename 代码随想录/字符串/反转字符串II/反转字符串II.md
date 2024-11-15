# 反转字符串II

# 1. 题目

题目链接：[https://leetcode.cn/problems/reverse-string-ii](https://leetcode.cn/problems/reverse-string-ii "https://leetcode.cn/problems/reverse-string-ii")

给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。

示例:

输入: s = "abcdefg", k = 2 &#x20;
输出: "bacdfeg"

# 2. 算法

```c++
class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        int start = 0;
        int last = n;
        while(last > 0)
        {
            if(last < k)
            {
                reverse(s, start, n - 1);
                break;
            }
            else if(last >= k && last < 2 * k)
            {
                reverse(s, start, start + k - 1);
                break;
            }
            else
            {
                reverse(s, start, start + k - 1);
                last -= 2 * k;
                start += 2 * k;
            }
        }
        return s;
    }

    void reverse(string& s, int start, int end)
    {
        for(int i = start, j = end; i <= start + (end - start) / 2; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }
};
```
