# P2895 \[USACO08FEB] Meteor Shower S

# \[USACO08FEB] Meteor Shower S

## 题面翻译

## 题目描述

贝茜听说一场特别的流星雨即将到来：这些流星会撞向地球，并摧毁它们所撞击的任何东西。她为自己的安全感到焦虑，发誓要找到一个安全的地方（一个永远不会被流星摧毁的地方）。

如果将牧场放入一个直角坐标系中，贝茜现在的位置是原点，并且，贝茜不能踏上一块被流星砸过的土地。

根据预报，一共有 $M$ 颗流星 $(1\leq M\leq 50,000)$ 会坠落在农场上，其中第 $i$ 颗流星会在时刻 $T_i$（$0 \leq T _ i \leq 1000$）砸在坐标为 $(X_i,Y_i)(0\leq X_i\leq 300$，$0\leq Y_i\leq 300)$ 的格子里。流星的力量会将它所在的格子，以及周围 $4$ 个相邻的格子都化为焦土，当然贝茜也无法再在这些格子上行走。

贝茜在时刻 $0$ 开始行动，她只能在第一象限中，平行于坐标轴行动，每 $1$ 个时刻中，她能移动到相邻的（一般是 $4$ 个）格子中的任意一个，当然目标格子要没有被烧焦才行。如果一个格子在时刻 $t$ 被流星撞击或烧焦，那么贝茜只能在 $t$ 之前的时刻在这个格子里出现。 贝茜一开始在 $(0,0)$。

请你计算一下，贝茜最少需要多少时间才能到达一个安全的格子。如果不可能到达输出 $−1$。

## 输入格式

共 $M+1$ 行，第 $1$ 行输入一个整数 $M$，接下来的 $M$ 行每行输入三个整数分别为 $X_i, Y_i, T_i$。

## 输出格式

贝茜到达安全地点所需的最短时间，如果不可能，则为 $-1$。

## 题目描述

Bessie hears that an extraordinary meteor shower is coming; reports say that these meteors will crash into earth and destroy anything they hit. Anxious for her safety, she vows to find her way to a safe location (one that is never destroyed by a meteor) . She is currently grazing at the origin in the coordinate plane and wants to move to a new, safer location while avoiding being destroyed by meteors along her way.

The reports say that M meteors (1 ≤ M ≤ 50,000) will strike, with meteor i will striking point (Xi, Yi) (0 ≤ Xi ≤ 300; 0 ≤ Yi ≤ 300) at time Ti (0 ≤ Ti  ≤ 1,000). Each meteor destroys the point that it strikes and also the four rectilinearly adjacent lattice points.

Bessie leaves the origin at time 0 and can travel in the first quadrant and parallel to the axes at the rate of one distance unit per second to any of the (often 4) adjacent rectilinear points that are not yet destroyed by a meteor. She cannot be located on a point at any time greater than or equal to the time it is destroyed).

Determine the minimum time it takes Bessie to get to a safe place.

## 输入格式

\\\* Line 1: A single integer: M

\\\* Lines 2..M+1: Line i+1 contains three space-separated integers: Xi, Yi, and Ti

## 输出格式

\\\* Line 1: The minimum time it takes Bessie to get to a safe place or -1 if it is impossible.

## 样例 #1

### 样例输入 #1

```c++
4
0 0 2
2 1 2
1 1 2
0 3 5
```

### 样例输出 #1

```c++
5
```

# 题解

注意这题人可以走到300开外

```c++
#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>
#include<queue>
#include<cstring>
#include<map>
using namespace std;


#define max_num 30
#define INFINITY 0x3f   
typedef pair<int, int> PII;


struct stone
{
  int x;
  int y;
  int t;
}stones[50010];
int arrive[510][510];
bool visited[510][510];
bool burned[510][510];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int m;
int idx = 1;
bool flag = false;
queue<vector<int>> que;


bool cmp(stone s1, stone s2)
{
  return s1.t < s2.t;
}


bool check(int x, int y)
{
  if (visited[x][y] == false && x >= 0 && y >= 0)
    return true;
  else
    return false;
}


void burn(int time)
{
  while (stones[idx].t == time)
  {
    int x = stones[idx].x;
    int y = stones[idx].y;
    visited[x][y] = true;
    if (x - 1 >= 0)
      visited[x - 1][y] = true;
    if (x + 1 <= 300)
      visited[x + 1][y] = true;
    if (y - 1 >= 0)
      visited[x][y - 1] = true;
    if (y + 1 <= 300)
      visited[x][y + 1] = true;
    idx++;
  }
}


void bfs()
{
  visited[0][0] = true;
  que.push({ 0,0,0 });
  burn(0);
  while (que.size())
  {
    int t_x = que.front()[0];
    int t_y = que.front()[1];
    int t_time = que.front()[2];
    que.pop();
    for (int i = 0; i < 4; i++)
    {
      int now_x = t_x + dx[i];
      int now_y = t_y + dy[i];
      int now_time = t_time + 1;
      burn(now_time);
      if (check(now_x, now_y) == true)
      {
        if (burned[now_x][now_y] == false)
        {
          cout << now_time << endl;
          flag = true;
          return;
        }
        visited[now_x][now_y] = true;
        arrive[now_x][now_y] = now_time;
        que.push({ now_x, now_y,now_time });
      }
    }
  }
}


int main()
{
  memset(arrive, 0x3f, sizeof arrive);
  cin >> m;
  for (int i = 1; i <= m; i++)
  {
    int x, y, t;
    cin >> x >> y >> t;
    stones[i].x = x;
    stones[i].y = y;
    stones[i].t = t;
    burned[x][y] = true;
    if (x - 1 >= 0)
      burned[x - 1][y] = true;
    burned[x + 1][y] = true;
    if (y - 1 >= 0)
      burned[x][y - 1] = true;
    burned[x][y + 1] = true;
  }
  sort(stones + 1, stones + m + 1, cmp);

  bfs();
  if (flag == false)
    cout << -1 << endl;
}
```
