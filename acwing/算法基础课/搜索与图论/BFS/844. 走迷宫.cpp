#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int n, m;
int a[110][110];
bool visited[110][110];
int cnt[110][110];

bool is_legal(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m && visited[x][y] == false && a[x][y] == 0)
        return true;
    else
        return false;
}

void bfs()
{
    queue<PII> que;
    que.push({1, 1});
    visited[1][1] = true;
    while (que.size())
    {
        int pos_x = que.front().first;
        int pos_y = que.front().second;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int temp_x = pos_x + dx[i];
            int temp_y = pos_y + dy[i];
            if (is_legal(temp_x, temp_y))
            {
                cnt[temp_x][temp_y] = cnt[pos_x][pos_y] + 1;
                if (temp_x == n && temp_y == m)
                {
                    return;
                }
                que.push({temp_x, temp_y});
                visited[temp_x][temp_y] = true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];

    bfs();
    cout << cnt[n][m] << endl;
    return 0;
}