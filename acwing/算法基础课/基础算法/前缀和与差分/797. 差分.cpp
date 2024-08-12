#include <iostream>
using namespace std;

int n, m;
int a[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 2; i--)
        a[i] -= a[i - 1];

    while (m--)
    {
        int l, r, c;
        cin >> l >> r >> c;
        a[l] += c;
        a[r + 1] -= c;
    }

    for (int i = 1; i <= n; i++)
    {
        a[i] += a[i - 1];
        cout << a[i] << " ";
    }
    return 0;
}