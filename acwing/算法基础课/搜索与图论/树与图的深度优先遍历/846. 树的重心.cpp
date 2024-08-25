#include <iostream>
using namespace std;

int h[200010];
int e[200010];
int ne[200010];
int idx = 0;
int n;
int ans = 100010;
bool visited[100010];

void insert(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dfs(int x)
{
    visited[x] = true;
    int total_nodes = 1;
    int this_tree;
    int max_node = -1;
    int last_node = n;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (visited[j] == false)
        {
            this_tree = dfs(j);
            total_nodes += this_tree;
            max_node = max(max_node, this_tree);
        }
    }
    last_node -= total_nodes;
    max_node = max(max_node, last_node);
    ans = min(ans, max_node);

    return total_nodes;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        h[i] = -1;

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        insert(a, b);
        insert(b, a);
    }

    dfs(1);
    cout << ans << endl;
    return 0;
}