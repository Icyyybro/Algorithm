#include<iostream>
using namespace std;

int n, k;
int ans = 0;
int p[100010];
int d[100010];


int find(int x)
{
    if (p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}


int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    while (k--)
    {
        int command, x, y;
        cin >> command >> x >> y;
        int px = find(x);
        int py = find(y);
        if (x > n || y > n)
        {
            ans++;
            continue;
        }
        if (command == 1)
        {
            if (px == py)
            {
                if ((d[y] - d[x]) % 3 != 0)
                    ans++;
            }
            else
            {
                p[px] = py;
                d[px] = d[y] - d[x];
            }
        }
        else
        {
            if (px == py)
            {
                if ((d[y] - d[x]) % 3 != 1&& (d[x] - d[y]) % 3 != 2)
                    ans++;
            }
            else
            {
                p[py] = px;
                d[py] = d[x] - d[y] + 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}


