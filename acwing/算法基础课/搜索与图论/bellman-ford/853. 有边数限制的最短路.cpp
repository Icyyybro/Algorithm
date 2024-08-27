#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 0x3f3f3f3f

struct Edge
{
    int x;
    int y;
    int w;
};

int n, m, k;
int dist[100010];
int back[100010];
bool visited[100010];
Edge edges[100010];

void bellman_ford()
{
    dist[1] = 0;
    for (int i = 1; i <= k; i++)
    {
        // 目标放在第一个参数
        memcpy(back, dist, sizeof back);
        for (int j = 1; j <= m; j++)
        {
            int x = edges[j].x;
            int y = edges[j].y;
            int w = edges[j].w;
            if (dist[y] > back[x] + w)
                dist[y] = back[x] + w;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i].x = a;
        edges[i].y = b;
        edges[i].w = w;
    }
    bellman_ford();
    if (dist[n] > MAX_LENGTH / 2)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
}