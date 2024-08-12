#include <iostream>
using namespace std;

int n;
int num;

int calculate(int a)
{
    int cnt = 0;
    while (a)
    {
        if (a & 1)
            cnt++;
        a = a >> 1;
    }
    return cnt;
}

int main()
{
    cin >> n;
    while (n--)
    {
        cin >> num;
        int ans = calculate(num);
        cout << ans << " ";
    }

    return 0;
}