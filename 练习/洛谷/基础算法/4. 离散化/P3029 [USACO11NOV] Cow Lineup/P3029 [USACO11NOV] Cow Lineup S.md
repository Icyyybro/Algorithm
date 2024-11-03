# P3029 \[USACO11NOV] Cow Lineup S

# \[USACO11NOV] Cow Lineup S

## 题面翻译

### 问题描述

农民约翰雇一个专业摄影师给他的部分牛拍照。由于约翰的牛有好多品种，他喜欢他的照片包含每

个品种的至少一头牛。

约翰的牛都站在一条沿线的不同地方， 每一头牛由一个整数位置 $X_i$ 以及整数品种编号 $ID_i$ 表示。

约翰想拍一张照片，这照片由沿线的奶牛的连续范围组成。照片的成本与规模相当，这就意味着，在一

系列照片中的最大和最小 $X$ 坐标的差距决定了照片的成本。

请帮助约翰计算最小的照片成本，这些照片中有每个不同的品种的至少一头牛，没有两头牛愿意站

在同一个地点的。

### 输入格式&#x20;

第 $1$ 行：牛的数量 $N$；

第 $2..1+N$ 行：每行包含 2 个以空格分隔的正整数 $X_i$ 和 $ID_i$；意义如题目描述；

### 输出格式&#x20;

输出共一行，包含每个不同品种 $\rm ID$ 的照片的最低成本。

## 题目描述

Farmer John has hired a professional photographer to take a picture of some of his cows.  Since FJ's cows represent a variety of different breeds, he would like the photo to contain at least one cow from each distinct breed present in his herd.

FJ's N cows are all standing at various positions along a line, each described by an integer position (i.e., its x coordinate) as well as an integer breed ID.  FJ plans to take a photograph of a contiguous range of cows along the line.  The cost of this photograph is equal its size -- that is, the difference between the maximum and minimum x coordinates of the cows in the range of the photograph.

Please help FJ by computing the minimum cost of a photograph in which there is at least one cow of each distinct breed appearing in FJ's herd.

## 输入格式

\\\* Line 1: The number of cows, N (1 <= N <= 50,000).&#x20;

\\\* Lines 2..1+N: Each line contains two space-separated positive integers specifying the x coordinate and breed ID of a single cow.  Both numbers are at most 1 billion.

## 输出格式

\\\* Line 1: The smallest cost of a photograph containing each distinct breed ID.

## 样例 #1

### 样例输入 #1

```bash
6 
25 7 
26 1 
15 1 
22 3 
20 1 
30 1
```

### 样例输出 #1

```bash
4
```

## 提示

There are 6 cows, at positions 25,26,15,22,20,30, with respective breed IDs 7,1,1,3,1,1.

The range from x=22 up through x=26 (of total size 4) contains each of the distinct breed IDs 1, 3, and 7 represented in FJ's herd.

# 题解

本题因为x太大，所以需要离散化，按照x大小排序，在读入的时候需要记录牛的种类（用map)。

```c++
for (int i = 1; i <= n; i++)
{
  cin >> cows[i].x >> cows[i].id;
  if (a[cows[i].id] == 0)
  {
    kinds++;
  }
  a[cows[i].id] = 1;
}
sort(cows + 1, cows + n + 1, cmp);
```

再用双指针算法解决问题。如果区间内牛种类小于kinds，那么r++,并更新区间内牛的种类nums以及区间内每个种类牛的数量cnt。

```c++
while (nums < kinds)
{
  r++;
  if (cnt[cows[r].id] == 0)
    nums++;
  cnt[cows[r].id]++;
}
```

更新完成右指针，开始更新左指针。如果左指针指向的牛的种类在区间中的数量大于1，l++，更新cnt。

```c++
while (cnt[cows[l].id] > 1)
{
  cnt[cows[l].id]--;
  l++;
}
```

更新答案ans

```c++
if (ans > cows[r].x - cows[l].x)
{
  ans = cows[r].x - cows[l].x;
}
```

r++,探索下一个可能的区间。

综合代码如下：

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;


#define max_num 50100
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


struct cow
{
  long long x;
  long long id;
}cows[max_num];
int n;
int kinds = 0;
map<long long, long long> a;        //第一个int是x，第二个int是id
map<long long, long long> cnt;        //第一个int是id,第二个int是id在窗口中出现的次数


bool cmp(cow c1, cow c2)
{
  return c1.x < c2.x;
}


int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> cows[i].x >> cows[i].id;
    if (a[cows[i].id] == 0)
    {
      kinds++;
    }
    a[cows[i].id] = 1;
  }
  sort(cows + 1, cows + n + 1, cmp);

  int l = 1, r = 0;
  long long ans = 1e9;
  int nums = 0;
  while (r <= n)
  {
    while (nums < kinds)
    {
      r++;
      if (cnt[cows[r].id] == 0)
        nums++;
      cnt[cows[r].id]++;
    }
    while (cnt[cows[l].id] > 1)
    {
      cnt[cows[l].id]--;
      l++;
    }
    if (ans > cows[r].x - cows[l].x)
    {
      ans = cows[r].x - cows[l].x;
    }
    r++;
    cnt[cows[r].id]++;
  }
  

  cout << ans << endl;
}
```

while (cnt\[cows\[l].id] > 1)

{

cnt\[cows\[l].id]--;

l++;

}
