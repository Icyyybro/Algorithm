# P2419 \[USACO08JAN] Cow Contest S

# \[USACO08JAN] Cow Contest S

## 题目描述

\$ N (1 ≤ N ≤ 100) \$ cows, conveniently numbered \$ 1 \~ N \$ , are participating in a programming contest. As we all know, some cows code better than others. Each cow has a certain constant skill rating that is unique among the competitors.

The contest is conducted in several head-to-head rounds, each between two cows. If cow \$ A \$ has a greater skill level than cow \$ B (1 ≤ A ≤ N; 1 ≤ B ≤ N; A ≠ B) \$, then cow \$ A \$ will always beat cow \$ B \$ .

Farmer John is trying to rank the cows by skill level. Given a list the results of \$ M (1 ≤ M ≤ 4,500) \$ two-cow rounds, determine the number of cows whose ranks can be precisely determined from the results. It is guaranteed that the results of the rounds will not be contradictory.

FJ的 $N$（$1 \leq N \leq 100$）头奶牛们最近参加了场程序设计竞赛。在赛场上，奶牛们按 $1, 2, \cdots, N$ 依次编号。每头奶牛的编程能力不尽相同，并且没有哪两头奶牛的水平不相上下，也就是说，奶牛们的编程能力有明确的排名。 整个比赛被分成了若干轮，每一轮是两头指定编号的奶牛的对决。如果编号为 $A$ 的奶牛的编程能力强于编号为 $B$ 的奶牛 （$1 \leq A, B \leq N$，$A \neq B$)，那么她们的对决中，编号为 $A$ 的奶牛总是能胜出。 FJ 想知道奶牛们编程能力的具体排名，于是他找来了奶牛们所有 $M$（$1 \leq M \leq 4,500$）轮比赛的结果，希望你能根据这些信息，推断出尽可能多的奶牛的编程能力排名。比赛结果保证不会自相矛盾。

## 输入格式

第一行两个用空格隔开的整数 $N, M$。

第 $2\sim M + 1$ 行，每行为两个用空格隔开的整数 $A, B$ ，描述了参加某一轮比赛的奶牛的编号，以及结果（每行的第一个数的奶牛为**胜者**）。

## 输出格式

输出一行一个整数，表示排名可以确定的奶牛的数目。

## 样例 #1

### 样例输入 #1

```c++
5 5
4 3
4 2
3 2
1 2
2 5
```

### 样例输出 #1

```c++
2
```

## 提示

样例解释：

编号为 $2$ 的奶牛输给了编号为 $1, 3, 4$ 的奶牛，也就是说她的水平比这 $3$ 头奶牛都差。而编号为 $5$ 的奶牛又输在了她的手下，也就是说，她的水平比编号为 $5$ 的奶牛强一些。于是，编号为 $2$ 的奶牛的排名必然为第 $4$，编号为 $5$ 的奶牛的水平必然最差。其他 $3$ 头奶牛的排名仍无法确定。

# 题解

本题可以用图来做，图的边表示胜负关系，所以这里我想到用两个图存储，一个图存储胜利关系，如果i→j证明i战胜j，一个图用来存储失败关系，如果i→j，则说明i失败于j。这样信息就完全了，然后使用floyd算法计算这两个图中各个点是否连通，如果i和所有点（除自身）都连通，那么相当于i和每个人都直接或间接交战过，知道自己的排名。代码如下：

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;



#define max_num 110
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


int n, m;
int graph1[max_num][max_num];
int graph2[max_num][max_num];
int initial[max_num][max_num];
bool is_sure[max_num];


int main()
{
  memset(is_sure, true, sizeof is_sure);
  memset(graph2, INFINITY, sizeof graph2);
  memset(graph1, INFINITY, sizeof graph1);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    graph1[a][b] = 1;
    graph2[b][a] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
        graph1[i][j] = min(graph1[i][j], graph1[i][k] + graph1[k][j]);
        graph2[i][j] = min(graph2[i][j], graph2[i][k] + graph2[k][j]);
      }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      if ((graph1[i][j] >= 0x3f3f3f3f && graph2[i][j] >= 0x3f3f3f3f)&&i!=j)
        is_sure[i] = false;
    }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (is_sure[i] == true)
      ans++;

  cout << ans << endl;
}
```

后来我发现，不用建立两个图，因为graph\[i]\[j]可以判断i是否可以战胜j，那么graph\[j]\[i]也可以判断j是否可以战胜i，换个说法就是i是否败给j了。所以判断任意两个点的排名高低，就可以通过graph\[i]\[j]和graph\[j]\[i]判断i是战胜j，还是败给j。

```c++
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;



#define max_num 110
#define INFINITY 0x3f   
typedef pair<long long, long long> PII;


int n, m;
int graph[max_num][max_num];
int initial[max_num][max_num];
bool is_sure[max_num];


int main()
{
  memset(is_sure, true, sizeof is_sure);
  memset(graph, INFINITY, sizeof graph);
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
      {
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
      }
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
    {
      if ((graph[i][j] >= 0x3f3f3f3f && graph[j][i] >= 0x3f3f3f3f) && i != j)
        is_sure[i] = false;
    }

  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (is_sure[i] == true)
      ans++;

  cout << ans << endl;
}
```
