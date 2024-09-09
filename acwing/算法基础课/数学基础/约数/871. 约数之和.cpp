#include <bits/stdc++.h>
using namespace std;

int n;
int a;
unordered_map<int, int> primes;
long long ans = 1;
long long inf = 1e9 + 7;

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
        long long temp = 1;
        for (int i = 1; i <= prime.second; i++)
        {
            temp = (temp * prime.first + 1) % inf;
        }
        ans = (ans * temp) % inf;
    }

    cout << ans << endl;
    return 0;
}