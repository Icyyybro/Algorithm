#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 0x3f3f3f3f

int n, m;
int dist[100010];
int graph[510][510];
bool visited[510];
int ans = 0;

void prim()
{
    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (visited[j] == false && (t == -1 || dist[t] > dist[j]))
                t = j;
        }
        if (i != 1 && dist[t] == MAX_LENGTH)
        {
            ans = MAX_LENGTH;
            return;
        }
        if (i != 1)
            ans += dist[t];
        visited[t] = true;
        dist[t] = 0;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], graph[t][j]);
    }
}

int main()
{
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    memset(graph, 0x3f, sizeof graph);
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = graph[b][a] = min(graph[a][b], w);
    }

    prim();
    if (ans == MAX_LENGTH)
        cout << "impossible" << endl;
    else
        cout << ans << endl;

    return 0;
}