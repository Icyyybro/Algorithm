#include <iostream>
using namespace std;

int n;
int a[100010];

void merge_sort(int st, int ed)
{
    if (st >= ed)
        return;
    int mid = st + ed >> 1;
    merge_sort(st, mid);
    merge_sort(mid + 1, ed);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}