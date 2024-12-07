# 复原 IP 地址

# 1. 题目

题目链接：[https://leetcode.cn/problems/restore-ip-addresses](https://leetcode.cn/problems/restore-ip-addresses "https://leetcode.cn/problems/restore-ip-addresses")

给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。

有效的 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效的 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168\@1.1" 是 无效的 IP 地址。

示例 1：

- 输入：s = "25525511135"
- 输出：\["255.255.11.135","255.255.111.35"]

示例 2：

- 输入：s = "0000"
- 输出：\["0.0.0.0"]

示例 3：

- 输入：s = "1111"
- 输出：\["1.1.1.1"]

示例 4：

- 输入：s = "010010"
- 输出：\["0.10.0.10","0.100.1.0"]

示例 5：

- 输入：s = "101023"
- 输出：\["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

提示：

- 0 <= s.length <= 3000
- s 仅由数字组成

# 2. 算法

```c++
class Solution {
public:
    vector<string> ans;
    vector<string> path;
    vector<string> restoreIpAddresses(string s) {
        if(s.size() == 0)
            return ans;
        backTracing(s, 0);
        return ans;
    }

    void backTracing(string s, int startIndex)
    {
        // 需要保证字符串遍历完成，路径中元素个数等于4
        if(startIndex >= s.size() && path.size() == 4)
        {
            transferIntoIP();
            return;
        }
        for(int i = startIndex; i < s.size() && path.size() < 4; i++)
        {
            if(judge(s, startIndex, i))
                path.push_back(s.substr(startIndex, i - startIndex + 1)); 
            else
                continue;
            backTracing(s, i + 1);
            path.pop_back();
        }
    }
    
    //判断是否合法
    bool judge(string s, int start, int end)
    {
        int sum = 0;
        //如果有两位即以上且第一位是0，则不合法。
        if(start != end && s[start] == '0')
            return false;
        
        for(int i = start; i <= end; i++)
        {
            sum = sum * 10;
            sum += s[i] - '0';
            //cout << sum << endl;
            if(sum > 255)
                return false;
        }
        return true;
    }

    //将路径拼接成带"."的IP
    void transferIntoIP()
    {
        string str;
        for(int i = 0; i < path.size(); i++)
        {
            str += path[i];
            if(i != path.size() - 1)
                str += ".";
        }
        ans.push_back(str);
    }
};
```
