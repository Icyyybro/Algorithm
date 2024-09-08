#include <iostream>
using namespace std;

int n;
int f[1010][1010];
int mod = 1e9 + 7;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        f[i][0] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] % mod;
            if (j >= i)
                f[i][j] = (f[i - 1][j] + f[i][j - i]) % mod;
        }

    cout << f[n][n] << endl;
    return 0;
}

// 优化
//  #include <iostream>
//  using namespace std;

// int n;
// int f[1010];
// int mod = 1e9 + 7;

// int main()
// {
//     cin >> n;
//     f[0] = 1;

//     for (int i = 1; i <= n; i++)
//         for (int j = 1; j <= n; j++)
//         {
//             if (j >= i)
//                 f[j] = (f[j] + f[j - i]) % mod;
//         }

//     cout << f[n] << endl;
//     return 0;
// }
