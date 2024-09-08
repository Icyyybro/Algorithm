#include <iostream>
using namespace std;

int n;
int cnt[100010];
int f[1010][1010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cnt[i];
        cnt[i] += cnt[i - 1];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            f[l][r] = 1e9;
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + cnt[r] - cnt[l - 1]);
        }
    }

    cout << f[1][n] << endl;
    return 0;
}