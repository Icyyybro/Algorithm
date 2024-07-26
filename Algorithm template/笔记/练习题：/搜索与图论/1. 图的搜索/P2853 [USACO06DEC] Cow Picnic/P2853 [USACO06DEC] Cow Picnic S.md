# P2853 \[USACO06DEC] Cow Picnic S

# \[USACO06DEC] Cow Picnic S

## 题目描述

The cows are having a picnic! Each of Farmer John's K (1 ≤ K ≤ 100) cows is grazing in one of N (1 ≤ N ≤ 1,000) pastures, conveniently numbered 1...N. The pastures are connected by M (1 ≤ M ≤ 10,000) one-way paths (no path connects a pasture to itself).

The cows want to gather in the same pasture for their picnic, but (because of the one-way paths) some cows may only be able to get to some pastures. Help the cows out by figuring out how many pastures are reachable by all cows, and hence are possible picnic locations.

$K(1 \le K \le 100)$ 只奶牛分散在 $N(1 \le N \le 1000)$ 个牧场．现在她们要集中起来进餐。牧场之间有 $M(1 \le M \le 10000)$ 条有向路连接，而且不存在起点和终点相同的有向路．她们进餐的地点必须是所有奶牛都可到达的地方。那么，有多少这样的牧场可供进食呢？

## 输入格式

Line 1: Three space-separated integers, respectively: K, N, and M

Lines 2..K+1: Line i+1 contains a single integer (1..N) which is the number of the pasture in which cow i is grazing.

Lines K+2..M+K+1: Each line contains two space-separated integers, respectively A and B (both 1..N and A != B), representing a one-way path from pasture A to pasture B.

## 输出格式

Line 1: The single integer that is the number of pastures that are reachable by all cows via the one-way paths.

## 样例 #1

### 样例输入 #1

```c++
2 4 4
2
3
1 2
1 4
2 3
3 4
```

### 样例输出 #1

```c++
2
```

## 提示

The cows can meet in pastures 3 or 4.

# 题解

反向建边，遍历每个牧场能否前往这k头牛所在的牧场。

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;


#define max_num 10010
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


int n, m;
int head[max_num];
long long e[max_num];
int ne[max_num];
int weight[max_num];
long long dist[max_num];
int cow[max_num];
int idx = 0;
bool visited[max_num];


void add(int x, int y)
{
  e[idx] = y;
  ne[idx] = head[x];
  head[x] = idx;
  idx++;
}


void dfs(int x)
{
  visited[x] = true;
  for (int i = head[x]; i != -1; i = ne[i])
  {
    int j = e[i];
    if (visited[j] == false)
      dfs(j);
  }
}


int main()
{
  int k, n, m;
  cin >> k >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    head[i] = -1;
  }
  for (int i = 1; i <= k; i++)
    cin >> cow[i];
  for (int i = 1; i <= m; i++)
  {
    int x, y;
    cin >> x >> y;
    add(y, x);
  }

  int ans = 0;
  for (int i = 1; i <= n; i++)
  {
    int flag = true;
    memset(visited, 0, sizeof visited);
    dfs(i);
    for (int i = 1; i <= k; i++)
    {
      if (visited[cow[k]] == false)
        flag = false;
    }
    if (flag == true)
      ans++;
  }

  cout << ans << endl;
}
```
