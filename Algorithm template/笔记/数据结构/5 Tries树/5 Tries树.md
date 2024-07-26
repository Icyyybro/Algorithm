# 5 Tries树

son\[i]\[26]表示第i个节点的26个孩子的序号
cnt\[]以当前节点结尾的单词有几个
idx当前分配的下标

# 1. 插入

```c++
void Tries_tree_insert(int son[][26], int cnt[], int idx, char str[])
{
  int p = 0;      //从根节点出发
  for (int i = 0; str[i]; i++)
  {
    int u = str[i] - 'a';
    if (!son[p][u])
      son[p][u] = ++idx;
    p = son[p][u];
  }
  cnt[p]++;   
}
```

# 2. 查询

```c++
int query(int son[][26], int cnt[], char str[])
{
  int p = 0;
  for (int i = 0; str[i]; i++)
  {
    int u = str[i] - 'a';
    if (!son[p][u])
      return;
    p = son[p][u];
  }
  return cnt[p];
}
```
