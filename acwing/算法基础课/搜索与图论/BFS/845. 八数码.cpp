#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dist;
unordered_map<string, bool> visited;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int path = -1;
string str = "";
string target = "12345678x";

bool judge(int x, int y)
{
    if (x >= 0 && x < 3 && y >= 0 && y < 3)
        return true;
    else
        return false;
}

int bfs()
{
    queue<string> que;
    dist[str] = 0;
    visited[str] = true;
    que.push(str);
    while (que.size())
    {
        auto temp = que.front();
        if (temp == target)
            return dist[target];
        que.pop();
        int pos = temp.find('x');
        int x = pos / 3;
        int y = pos % 3;
        for (int i = 0; i < 4; i++)
        {
            int t_x = x + dx[i];
            int t_y = y + dy[i];
            if (judge(t_x, t_y) == true)
            {
                int new_pos = t_x * 3 + t_y;
                string new_str = temp;
                swap(new_str[pos], new_str[new_pos]);
                if (visited[new_str] == false)
                {
                    dist[new_str] = dist[temp] + 1;
                    visited[new_str] = true;
                    que.push(new_str);
                }
            }
        }
    }
    return -1;
}

int main()
{
    char c;
    for (int i = 0; i < 9; i++)
    {
        cin >> c;
        str.push_back(c);
    }
    cout << bfs() << endl;
}