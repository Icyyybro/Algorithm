#include <iostream>
using namespace std;

int n, m, x;
int a[100010];
int b[100010];

int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];
    int i = 0;
    int j = m - 1;
    for (i = 0; i < n; i++)
    {
        while (a[i] + b[j] > x)
            j--;
        if (a[i] + b[j] == x)
        {
            cout << i << " " << j << endl;
            return 0;
        }
    }

    return 0;
}