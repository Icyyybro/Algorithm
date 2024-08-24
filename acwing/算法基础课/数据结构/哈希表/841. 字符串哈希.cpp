#include <iostream>
using namespace std;
#define P 131

char str[100010];
unsigned long long p[100010];
unsigned long long hash_value[100010];
int n, m;

unsigned long long calculate(int l, int r)
{
    return hash_value[r] - hash_value[l - 1] * p[r - l + 1];
}

int main()
{
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        p[i] = p[i - 1] * P;
        hash_value[i] = hash_value[i - 1] * P + str[i];
    }

    while (m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (calculate(l1, r1) == calculate(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}