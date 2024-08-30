#include <iostream>
using namespace std;

int N, V;
int v[110][110];
int w[110][110];
int f[110];
int num[110];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
    {
        cin >> num[i];
        for (int j = 1; j <= num[i]; j++)
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= N; i++)
        for (int k = V; k >= 0; k--)
            for (int j = 1; j <= num[i]; j++)
            {
                if (k >= v[i][j])
                    f[k] = max(f[k], f[k - v[i][j]] + w[i][j]);
            }

    cout << f[V] << endl;
    return 0;
}