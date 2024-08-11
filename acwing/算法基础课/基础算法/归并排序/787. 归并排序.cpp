#include <iostream>
#include <vector>
using namespace std;

int n;
int a[100010];
vector<int> temp;

void merge_sort(int st, int ed)
{
    if (st >= ed)
        return;
    int mid = st + ed >> 1;
    merge_sort(st, mid);
    merge_sort(mid + 1, ed);
    int i = st;
    int j = mid + 1;
    while (i <= mid && j <= ed)
    {
        if (a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
        }
    }
    while (i <= mid)
        temp.push_back(a[i++]);
    while (j <= ed)
        temp.push_back(a[j++]);
    int ptr = 0;
    for (int i = st; i <= ed; i++)
        a[i] = temp[ptr++];
    temp.clear();
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    merge_sort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}