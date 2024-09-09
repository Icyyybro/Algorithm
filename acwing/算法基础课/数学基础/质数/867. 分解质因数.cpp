#include <iostream>
using namespace std;

int n;
int a;

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> a;
        for (int i = 2; i <= a / i; i++)
        {
            int cnt = 0;
            while (a % i == 0)
            {
                cnt++;
                a = a / i;
            }
            if (cnt > 0)
                cout << i << " " << cnt << endl;
        }
        if (a > 1)
            cout << a << " " << 1 << endl;
        cout << endl;
    }

    return 0;
}