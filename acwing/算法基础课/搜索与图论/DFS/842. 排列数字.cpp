#include <iostream>
#include <vector>
using namespace std;

int n;
bool visited[10];
vector<int> path;

void dfs(int x)
{
    visited[x] = true;
    path.push_back(x);
    if (path.size() == n)
    {
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == false)
        {
            dfs(i);
            visited[i] = false;
            path.pop_back();
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dfs(i);
        visited[i] = false;
        path.pop_back();
    }

    return 0;
}