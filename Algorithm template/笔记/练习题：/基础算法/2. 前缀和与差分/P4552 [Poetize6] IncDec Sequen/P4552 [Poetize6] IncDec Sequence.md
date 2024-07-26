# P4552 \[Poetize6] IncDec Sequence

# \[Poetize6] IncDec Sequence

## 题目描述

给定一个长度为 $n$ 的数列 ${a_1,a_2,\cdots,a_n}$，每次可以选择一个区间$[l,r]$，使这个区间内的数都加 $1$ 或者都减 $1$。&#x20;

请问至少需要多少次操作才能使数列中的所有数都一样，并求出在保证最少次数的前提下，最终得到的数列有多少种。

## 输入格式

第一行一个正整数 $n$  &#x20;

接下来 $n$ 行,每行一个整数,第 \$i+1 \$行的整数表示 $a_i$。

## 输出格式

第一行输出最少操作次数  &#x20;

第二行输出最终能得到多少种结果

## 样例 #1

### 样例输入 #1

```c++
4
1
1
2
2
```

### 样例输出 #1

```c++
1
2
```

## 提示

对于 $100\%$ 的数据，$n\le 100000, 0 \le a_i \le 2^{31}$。

# 题解

这道题需要用差分，差分化数组的含义是，a\[i]表示第i个元素和第i-1个元素大多少，第一个元素的差分数等于它本身。这样，我们就需要将差分数组除了元素1以外的数都变为0，也就是后一个数和前一个数差距为0。这样数组里的数都和元素1相等。

差分化数组在一个区间\[l, r]内同时加一个数时，有三种情况：

1. 只需要把diff\[l]+1，diff\[r+1]-1就可以；
2. 当r=n时，只需要diff\[l]+1。
3. 当l=1时，只需要diff\[r+1]-1。

所以我们就考虑差分数组（除元素1）中正数之和等于多少（p），负数之和的绝对值为多少（q），它们两当中最大的，就是我需要做的操作次数。

通过上述加减1，我们可以把所有元素变成与元素1相等的数。那么，可以得到的数组有多少种，就相当于元素1有多少种。很简单，其实就是看看有几种一步步减或一步步加的操作数，因为我们一步步加的时候（假设我们现在的操作对象下标为i），可以这样操作，b\[1]-1,b\[i]+1一步步减的时候可以这样操作，b\[1]+1,b\[i]-1。所以只有变换1个diff时，1号元素才会发生变换。所以答案就是abs(p-q)+1，加1是因为1号元素本身有1个值，就算你不操作它，它也算一种情况。

代码如下：

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;


#define max_num 1010000
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


long long a[max_num];
long long diff[max_num];
int n;


int main()
{
  cin >> n;
  long long ans_f = 0, ans_z = 0, ans;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
  }

  for (int i = 2; i <= n; i++)
  {
    diff[i] = a[i] - a[i - 1];
    if (diff[i] < 0)
      ans_f -= diff[i];
    else
      ans_z += diff[i];
  }

  ans = max(ans_f, ans_z);
  long long num = abs(ans_f - ans_z) + 1;

  cout << ans << endl;
  cout << num << endl;
}
```
