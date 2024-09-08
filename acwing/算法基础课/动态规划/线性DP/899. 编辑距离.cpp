#include <bits/stdc++.h>
using namespace std;

int n, m;
int f[1010][1010];
char a[1010][20];
char b[20];
int cnt;

bool judge(char *str1, char *str2, int max_action)
{
    int len1 = strlen(str1 + 1);
    int len2 = strlen(str2 + 1);
    for (int i = 1; i <= len1; i++)
        f[i][0] = i;
    for (int i = 1; i <= len2; i++)
        f[0][i] = i;

    for (int i = 1; i <= len1; i++)
        for (int j = 1; j <= len2; j++)
        {
            f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1);
            if (str1[i] == str2[j])
                f[i][j] = min(f[i - 1][j - 1], f[i][j]);
            else
                f[i][j] = min(f[i - 1][j - 1] + 1, f[i][j]);
        }

    if (f[len1][len2] <= max_action)
        return true;
    else
        return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i] + 1;

    while (m--)
    {
        cin >> b + 1;
        int max_action;
        cin >> max_action;
        cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (judge(a[i], b, max_action))
                cnt++;
            else
                continue;
        }
        cout << cnt << endl;
    }

    return 0;
}