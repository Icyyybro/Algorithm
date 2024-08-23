#include <iostream>
using namespace std;

int n, m;
int cnt[100010];
int p[100010];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void insert(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
        return;
    p[fa] = fb;
    cnt[fb] += cnt[fa];
}

int query(int x)
{
    int px = find(x);
    return cnt[px];
}

bool judge(int a, int b)
{
    int fa = find(a);
    int fb = find(b);
    if (fa == fb)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cnt[i] = 1;
        p[i] = i;
    }

    while (m--)
    {
        string command;
        int a, b;
        cin >> command;
        if (command == "C")
        {
            cin >> a >> b;
            insert(a, b);
        }
        else if (command == "Q1")
        {
            cin >> a >> b;
            if (judge(a, b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
        else
        {
            cin >> a;
            cout << query(a) << endl;
        }
    }

    return 0;
}