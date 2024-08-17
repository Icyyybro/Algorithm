#include <bits/stdc++.h>
using namespace std;

int n, k, x;
deque<int> num;
int a[1000010];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        if (i > k && num.front() == i - k)
            num.pop_front();
        while (num.size() && a[num.back()] > a[i])
            num.pop_back();
        num.push_back(i);
        if (i >= k)
            cout << a[num.front()] << " ";
    }

    num.clear();
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        if (i > k && num.front() == i - k)
            num.pop_front();
        while (num.size() && a[num.back()] < a[i])
            num.pop_back();
        num.push_back(i);
        if (i >= k)
            cout << a[num.front()] << " ";
    }
}