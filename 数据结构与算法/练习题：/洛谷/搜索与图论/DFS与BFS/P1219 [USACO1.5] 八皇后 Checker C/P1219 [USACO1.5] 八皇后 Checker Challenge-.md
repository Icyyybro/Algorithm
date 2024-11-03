P1219 \[USACO1.5] 八皇后 Checker Challenge

# \[USACO1.5] 八皇后 Checker Challenge

## 题目描述

一个如下的 $6 \times 6$ 的跳棋棋盘，有六个棋子被放置在棋盘上，使得每行、每列有且只有一个，每条对角线（包括两条主对角线的所有平行线）上至多有一个棋子。

![](https://cdn.luogu.com.cn/upload/image_hosting/3h71x0yf.png)

上面的布局可以用序列 $2\ 4\ 6\ 1\ 3\ 5$ 来描述，第 $i$ 个数字表示在第 $i$ 行的相应位置有一个棋子，如下：

行号 $1\ 2\ 3\ 4\ 5\ 6$

列号 $2\ 4\ 6\ 1\ 3\ 5$

这只是棋子放置的一个解。请编一个程序找出所有棋子放置的解。 &#x20;

并把它们以上面的序列方法输出，解按字典顺序排列。 &#x20;

请输出前 $3$ 个解。最后一行是解的总个数。

## 输入格式

一行一个正整数 $n$，表示棋盘是 $n \times n$ 大小的。

## 输出格式

前三行为前三个解，每个解的两个数字之间用一个空格隔开。第四行只有一个数字，表示解的总数。

## 样例 #1

### 样例输入 #1

```c++
6
```

### 样例输出 #1

```c++
2 4 6 1 3 5
3 6 2 5 1 4
4 1 5 2 6 3
4
```

## 提示

【数据范围】 &#x20;

对于 $100\%$ 的数据，$6 \le n \le 13$。

题目翻译来自NOCOW。

USACO Training Section 1.5

# 题解

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
typedef pair<long long, long long> PII;


vector<vector<int>> answers_list;
vector<int> ans;
int n;
bool visited_colum[max_num];
bool visited_left_to_right[max_num];
bool visited_right_to_left[max_num];


void visit(int x, int y)
{
  visited_left_to_right[x - y + n] = true;
  visited_right_to_left[y + x - 1] = true;
  visited_colum[y] = true;
}


void recall_visit(int x, int y)
{
  visited_left_to_right[x - y + n] = false;
  visited_right_to_left[y + x - 1] = false;
  visited_colum[y] = false;
}


bool check(int x, int y)
{
  if (visited_left_to_right[x - y + n] == false && visited_right_to_left[y + x - 1] == false && visited_colum[y] == false)
    return true;
  return false;
}


void dfs(int x, int y)
{
  visit(x, y);
  ans.push_back(y);
  if (x == n)
  {
    answers_list.push_back(ans);
    return;
  }
    
  for (int i = 1; i <= n; i++)
  {
    if (check(x + 1, i))
    {
      dfs(x + 1, i);
      ans.pop_back();
      recall_visit(x + 1, i);
    }
  }
}


int main()
{
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    memset(visited_colum, false, sizeof visited_colum);
    memset(visited_left_to_right, false, sizeof visited_left_to_right);
    memset(visited_right_to_left, false, sizeof visited_right_to_left);
    ans.clear();
    dfs(1, i);
  }

  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < answers_list[i].size(); j++)
      cout << answers_list[i][j] << " ";
    cout << endl;
  }
  cout << answers_list.size() << endl;
}
```
