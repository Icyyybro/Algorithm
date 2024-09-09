#include <bits/stdc++.h>
using namespace std;

long long inf = 1e9 + 7;
int n;
int a;
unordered_map<int, int> primes;
long long ans = 1;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a;
        for (int i = 2; i <= a / i; i++)
        {
            while (a % i == 0)
            {
                primes[i]++;
                a = a / i;
            }
        }
        if (a > 1)
            primes[a]++;
    }

    for (auto prime : primes)
    {
        ans *= (prime.second + 1);
        ans %= inf;
    }

    cout << ans << endl;
    return 0;
}