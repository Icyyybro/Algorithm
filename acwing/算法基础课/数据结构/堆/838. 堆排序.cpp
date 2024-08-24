#include <iostream>
using namespace std;

int n, m;
int a[100010];

void down(int x)
{
    int l_child = 2 * x;
    int r_child = 2 * x + 1;
    int pos = x;
    if (l_child <= n && a[l_child] < a[pos])
        pos = l_child;
    if (r_child <= n && a[r_child] < a[pos])
        pos = r_child;
    if (pos != x)
    {
        swap(a[pos], a[x]);
        down(pos);
    }
}

void heap_sort()
{
    for (int i = n / 2; i > 0; i--)
        down(i);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    heap_sort();

    while (m--)
    {
        cout << a[1] << " ";
        a[1] = a[n];
        n--;
        down(1);
    }

    return 0;
}