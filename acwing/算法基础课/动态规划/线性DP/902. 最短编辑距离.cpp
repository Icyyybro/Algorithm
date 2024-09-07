#include <iostream>
using namespace std;

char str1[1010];
char str2[1010];
int n, m;
int f[1010][1010];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> str1[i];
        f[i][0] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> str2[i];
        f[0][i] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (str1[i] == str2[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    cout << f[n][m] << endl;
    return 0;
}