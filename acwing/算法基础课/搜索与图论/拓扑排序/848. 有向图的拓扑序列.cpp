#include <bits/stdc++.h>
using namespace std;

int n, m;
int h[100010];
int e[100010];
int ne[100010];
int in_degree[100010];
int idx = 0;
queue<int> start;
vector<int> output;
bool visited[100010];

void insert(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
    in_degree[b]++;
}

void zero_node()
{
    for (int i = 1; i <= n; i++)
        if (in_degree[i] == 0)
        {
            start.push(i);
            visited[i] = true;
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
    zero_node();

    while (start.size())
    {
        int node = start.front();
        start.pop();
        output.push_back(node);
        for (int i = h[node]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (visited[j] == false)
            {
                in_degree[j]--;
                if (in_degree[j] == 0)
                {
                    start.push(j);
                    visited[j] = true;
                }
            }
        }
    }

    if (output.size() == n)
        for (int i = 0; i < output.size(); i++)
            cout << output[i] << " ";
    else
        cout << -1 << endl;
}