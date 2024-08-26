#include<bits/stdc++.h>
using namespace std;
# define MAX_LENGTH 0x3f3f3f3f

typedef pair<int, int> PII;

int h[100010];
int e[100010];
int ne[100010];
int w[100010];
int dist[100010];
bool visited[100010];
int n, m;
int idx = 0;

void insert(int a, int b, int weight)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = weight;
    h[a] = idx;
    idx++;
}

void dijkstra()
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({0, 1});
    while(heap.size())
    {
        auto temp = heap.top();
        heap.pop();
        int pos = temp.second;
        int distance = temp.first;
        if(visited[pos])
            continue;
        visited[pos] = true;
        for (int i = h[pos]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++)
        h[i] = -1;

    for (int i = 1; i <= m; i++)
    {
        int a, b, weight;
        cin >> a >> b >> weight;
        insert(a, b, weight);
    }
    dijkstra();

    if(dist[n] == MAX_LENGTH)
        cout << -1 << endl;
    else
        cout << dist[n] << endl;

    return 0;
}