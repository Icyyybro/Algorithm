#include <iostream>
using namespace std;

int n, m;
int a[100010];
int b[100010];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    int i = 1;
    int j = 1;
    for (i = 1; i <= n; i++)
    {
        while (j <= m && a[i] != b[j])
            j++;
        if (j > m)
        {
            cout << "No" << endl;
            return 0;
        }
        j++;
    }
    cout << "Yes" << endl;

    return 0;
}