#include<iostream>
using namespace std;

int n;
int a[100010];

void quick_sort(int st, int ed)
{
    if(st >= ed)
        return;
    int mid = a[st + ed >> 1];
    int i = st - 1;
    int j = ed + 1;
    while(i < j)
    {
        do
            i++;
        while (a[i] < mid);
        do
            j--;
        while (a[j] > mid);
        if(i < j)
            swap(a[i], a[j]);
    }
    quick_sort(st, j);
    quick_sort(j + 1, ed);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    quick_sort(1, n);

    for (int i = 1; i <= n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}