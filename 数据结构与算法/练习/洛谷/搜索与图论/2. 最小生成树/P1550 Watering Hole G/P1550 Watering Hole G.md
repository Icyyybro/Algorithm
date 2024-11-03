# P1550 Watering Hole G

# \[USACO08OCT] Watering Hole G

## 题目描述

Farmer John 的农场缺水了。

他决定将水引入到他的 $n$ 个农场。他准备通过挖若干井，并在各块田中修筑水道来连通各块田地以供水。在第 $i$ 号田中挖一口井需要花费 $W_i$ 元。连接 $i$ 号田与 $j$ 号田需要 $P_{i,j}$（$P_{j,i}=P_{i,j}$）元。

请求出 FJ 需要为使所有农场都与有水的农场相连或拥有水井所需要的最少钱数。

## 输入格式

第一行为一个整数 $n$。

接下来 $n$ 行，每行一个整数 $W_i$。

接下来 $n$ 行，每行 $n$ 个整数，第 $i$ 行的第 $j$ 个数表示连接 $i$ 号田和 $j$ 号田需要的费用 $P_{i,j}$。

## 输出格式

输出最小开销。

## 样例 #1

### 样例输入 #1

```c++
4
5
4
4
3
0 2 2 2
2 0 3 3
2 3 0 4
2 3 4 0
```

### 样例输出 #1

```c++
9
```

## 提示

对于 $100\%$ 的数据，$1 \leq n \leq 300$，$1 \leq W_i \leq 10^5$，$0 \leq P_{i,j} \leq 10^5$。

# 题解

注意此题并没有说明只允许打一个井，所以如果a到b的路程大于打一口井的消耗，那就可以通过打井而不连水管。

我们可以把这个打井看成：现有一个水源点，水源点到各个农场的距离为$W_i
 $，所以此题就变成求n+1个节点的图的最小生成树（1个水源点，n个农场）

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

#define max_num 310
#define INFINITY 0x3f
typedef pair<int, int> PII;

int dist[max_num];
bool state[max_num];
int graph[max_num][max_num];
int w[max_num];


int main()
{
  memset(dist, INFINITY, sizeof dist);
  memset(graph, INFINITY, sizeof graph);
  memset(state, false, sizeof state);

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
    graph[0][i] = w[i];
  }

  for(int i=1;i<=n;i++)
    for (int j = 1; j <= n; j++)
    {
      int x;
      cin >> x;
      graph[i][j] = graph[j][i] = x;
    }


  int res = 0;
  for (int i = 0; i <= n; i++)
  {
    int t = -1;
    for (int j = 0; j <= n; j++)
    {
      if (state[j] == false && (t == -1 || dist[t] > dist[j]))
        t = j;
    }
    state[t] = true;
    if (i != 0)
      res += dist[t];
    for (int j = 0; j <= n; j++)
    {
      dist[j] = min(dist[j], graph[t][j]);
    }
  }

  cout << res << endl;
}
```
