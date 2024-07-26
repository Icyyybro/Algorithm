# P1182 数列分段 Section II

# 数列分段 Section II

## 题目描述

对于给定的一个长度为 $N$ 的正整数数列 $A_{1\sim N}$，现要将其分成 $M$（$M\leq N$）段，并要求每段连续，且每段和的最大值最小。

关于最大值最小：

例如一数列 $4\ 2\ 4\ 5\ 1$ 要分成 $3$ 段。

将其如下分段：

$$
[4\ 2][4\ 5][1]
$$

第一段和为 $6$，第 $2$ 段和为 $9$，第 $3$ 段和为 $1$，和最大值为 $9$。

将其如下分段：

$$
[4][2\ 4][5\ 1]
$$

第一段和为 $4$，第 $2$ 段和为 $6$，第 $3$ 段和为 $6$，和最大值为 $6$。

并且无论如何分段，最大值不会小于 $6$。

所以可以得到要将数列 $4\ 2\ 4\ 5\ 1$ 要分成 $3$ 段，每段和的最大值最小为 $6$。

## 输入格式

第 $1$ 行包含两个正整数 $N,M$。 &#x20;

第 $2$ 行包含 $N$ 个空格隔开的非负整数 $A_i$，含义如题目所述。

## 输出格式

一个正整数，即每段和最大值最小为多少。

## 样例 #1

### 样例输入 #1

```c++
5 3
4 2 4 5 1
```

### 样例输出 #1

```c++
6
```

## 提示

对于 $20\%$ 的数据，$N\leq 10$。

对于 $40\%$ 的数据，$N\leq 1000$。

对于 $100\%$ 的数据，$1\leq N\leq 10^5$，$M\leq N$，$A_i < 10^8$， 答案不超过 $10^9$。

# 题解

二分答案，left=数组中最大的元素，right=数组元素和。

在check函数中，使用贪心思想，计算最少需要分成几个数组（使每个小数组装到不能装为止）。

```c++
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;


#define max_num 101000
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


int a[max_num];
long long sum[max_num];
int n, m;


bool check(long long x)
{
  int tot = 0, num = 0;
  for (int i = 1; i <= n; i++)
  {
    if (tot + a[i] <= x)
      tot += a[i];
    else
    {
      tot = a[i];
      num++;
    }
  }
  num++;
  if (num > m)
    return false;
  else
    return true;
}


int main()
{
  cin >> n >> m;
  int low = -1;
  for (int i = 1; i <= n; i++)
  {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    low = max(low, a[i]);
  }

  long long left = low, right = sum[n];
  while (left < right)
  {
    long long mid = left + right>> 1;
    if (check(mid) == true)
      right = mid;
    else
      left = mid + 1;
  }

  cout << left << endl;
}
```
