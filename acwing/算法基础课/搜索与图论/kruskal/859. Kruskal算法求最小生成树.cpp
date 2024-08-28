#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int w;
    int x;
    int y;
};

int n, m;
int p[100010];
int ans = 0;
int cnt = 0;
Edge edges[200010];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);
    return p[x];
}

bool cmp(Edge e1, Edge e2)
{
    return e1.w < e2.w;
}

void insert(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return;
    p[pa] = pb;
}

bool judge(int a, int b)
{
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
        return true;
    else
        return false;
}

bool kruskal()
{
    sort(edges + 1, edges + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        int x = edges[i].x;
        int y = edges[i].y;
        int w = edges[i].w;
        if (judge(x, y) == false)
        {
            cnt++;
            insert(x, y);
            ans += w;
        }
        if (cnt == n - 1)
            return true;
    }
    if (cnt < n - 1)
        return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].x = a;
        edges[i].y = b;
        edges[i].w = w;
    }

    if (kruskal())
        cout << ans << endl;
    else
        cout << "impossible" << endl;
    return 0;
}