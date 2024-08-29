#include<iostream>
using namespace std;

int v[1010];
int w[1010];
int N, V;
int f[1010];

int main()
{
    cin >> N >> V;
    for (int i = 1; i <= N; i++)
        cin >> v[i] >> w[i];

    for (int i = 1; i <= N; i++)
        for (int j = 0; j <= V; j++)
        {
            if(j >= v[i])
                f[j] = max(f[j], f[j - v[i]] + w[i]);
        }

    cout << f[V] << endl;
    return 0;
}