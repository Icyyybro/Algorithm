#include <bits/stdc++.h>
using namespace std;

double n;

int main()
{
    cin >> n;
    double left = -30;
    double right = 30;
    while (right - left > 0.0000001)
    {
        double mid = (left + right) / 2.0;
        if (pow(mid, 3) == n)
        {
            cout << left << endl;
            return 0;
        }
        else if (pow(mid, 3) < n)
            left = mid;
        else
            right = mid;
    }
    printf("%.6lf", left);
}