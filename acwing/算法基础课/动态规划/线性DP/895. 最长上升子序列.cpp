#include <iostream>
using namespace std;

int n;
int a[1010];
int f[1010];


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[i] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
    }

    int ans = 1;
    for (int i = 1; i <= n; i++)
        ans = max(ans, f[i]);

    cout << ans << endl;
    return 0;
}