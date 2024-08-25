#include<bits/stdc++.h>
using namespace std;

int n, m;
int h[100010];
int e[100010];
int ne[100010];
int idx = 0;
bool visited[100010];
int cnt[100010];

void insert(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void bfs()
{
    queue<int> que;
    que.push(1);
    visited[1] = true;
    while(que.size())
    {
        int temp = que.front();
        que.pop();
        for (int i = h[temp]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(visited[j] == false)
            {
                cnt[j] = cnt[temp] + 1;
                que.push(j);
                visited[j] = true;
                if(j == n)
                    return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        h[i] = -1;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b);
    }

    bfs();
    //注意：距离可能为0
    if(visited[n])
        cout << cnt[n] << endl;
    else
        cout << -1 << endl;
    return 0;
}