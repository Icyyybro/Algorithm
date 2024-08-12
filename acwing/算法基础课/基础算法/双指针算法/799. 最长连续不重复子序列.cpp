#include <iostream>
using namespace std;

int n;
int a[100010];
int cnt[100010];
int answer = -1;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int i = 1;
    int j = 1;
    for (int j = 1; j <= n; j++)
    {
        cnt[a[j]]++;
        if (cnt[a[j]] < 2)
            answer = max(answer, j - i + 1);
        while (cnt[a[j]] > 1)
        {
            cnt[a[i]]--;
            i++;
        }
    }
    cout << answer << endl;
    return 0;
}