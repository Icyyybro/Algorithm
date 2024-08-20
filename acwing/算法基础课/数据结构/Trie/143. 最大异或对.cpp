#include <bits/stdc++.h>
using namespace std;

int son[3100010][2];
int a[100010];
int n;
int idx = 1;
int ans = -1;

void insert(int x)
{
    int pos = 0;
    for (int i = 31; i >= 0; i--)
    {
        int temp = x >> i & 1;
        if (son[pos][temp])
            pos = son[pos][temp];
        else
        {
            son[pos][temp] = idx;
            pos = idx;
            idx++;
        }
    }
}

int find(int x)
{
    int sum = 0;
    int pos = 0;
    for (int i = 31; i >= 0; i--)
    {
        int temp = x >> i & 1;
        if (son[pos][1 - temp])
        {
            pos = son[pos][1 - temp];
            sum += pow(2, i);
        }
        else
        {
            pos = son[pos][temp];
        }
    }
    return sum;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        insert(a[i]);
    }

    for (int i = 1; i <= n; i++)
        ans = max(ans, find(a[i]));

    cout << ans << endl;
    return 0;
}