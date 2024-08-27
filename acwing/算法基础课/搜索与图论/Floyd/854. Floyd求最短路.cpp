#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 0x3f3f3f3f

int graph[210][210];
int n, m, k;

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
                graph[i][j] = MAX_LENGTH;
            else
                graph[i][j] = 0;
        }

    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a][b] = min(graph[a][b], w);
    }

    for (int t = 1; t <= n; t++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                graph[i][j] = min(graph[i][j], graph[i][t] + graph[t][j]);
            }

    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (graph[a][b] > MAX_LENGTH / 2)
            cout << "impossible" << endl;
        else
            cout << graph[a][b] << endl;
    }

    return 0;
}