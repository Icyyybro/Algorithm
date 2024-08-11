#include <iostream>
#include <vector>
using namespace std;

int n, q;
int a[100010];

int binary_sort_left(int target)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (a[mid] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (a[left] == target)
        return left;
    else
        return -1;
}

int binary_sort_right(int target)
{
    int left = 0;
    int right = n - 1;
    while (left < right)
    {
        int mid = left + right + 1 >> 1;
        if (a[mid] <= target)
            left = mid;
        else
            right = mid - 1;
    }
    if (a[left] == target)
        return left;
    else
        return -1;
}

int main()
{
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    while (q--)
    {
        int target;
        cin >> target;
        int left = binary_sort_left(target);
        int right = binary_sort_right(target);
        cout << left << " " << right << endl;
    }
    return 0;
}