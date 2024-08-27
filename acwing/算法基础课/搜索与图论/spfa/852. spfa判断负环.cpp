#include <bits/stdc++.h>
using namespace std;
#define MAX_LENGTH 0x3f3f3f3f

int n, m;
bool visited[100010];
int dist[100010];
int cnt[100010];
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

bool spfa()
{
    queue<int> que;
    for (int i = 1; i <= n; i++)
    {
        que.push(i);
        visited[i] = true;
        dist[i] = 0;
    }

    while(que.size())
    {
        int temp = que.front();
        que.pop();
        visited[temp] = false;
        for (int i = h[temp]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[temp] + w[i])
            {
                dist[j] = dist[temp] + w[i];
                cnt[j] = cnt[temp] + 1;
                if(cnt[j] >= n)
                    return true;
                if(visited[j] == false)
                {
                    visited[j] = true;
                    que.push(j);
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        h[i] = -1;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        insert(a, b, w);
    }

    if (spfa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}