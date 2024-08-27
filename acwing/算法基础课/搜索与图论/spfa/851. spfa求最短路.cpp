#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 0x3f3f3f3f

int n, m;
int dist[100010];
bool visited[100010];
int h[100010];
int e[100010];
int ne[100010];
int w[100010];
int idx = 0;

void insert(int a, int b, int weight)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = weight;
    h[a] = idx;
    idx++;
}

void spfa()
{
    queue<int> que;
    dist[1] = 0;
    visited[1] = true;
    que.push(1);
    while (que.size())
    {
        int temp = que.front();
        que.pop();
        visited[temp] = false;
        for (int i = h[temp]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[temp] + w[i])
            {
                dist[j] = dist[temp] + w[i];
                if (visited[j] == false)
                {
                    visited[j] = true;
                    que.push(j);
                }
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    memset(dist, 0x3f, sizeof dist);

    for (int i = 1; i <= m; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        insert(a, b, weight);
    }

    spfa();
    if (dist[n] > MAX_LENGTH / 2)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
}