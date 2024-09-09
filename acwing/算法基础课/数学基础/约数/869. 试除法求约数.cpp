#include <bits/stdc++.h>
using namespace std;

int n;
int a;
vector<int> ans;

int main()
{
    cin >> n;
    while (n--)
    {
        ans.clear();
        cin >> a;
        for (int i = 1; i <= a / i; i++)
        {
            if (a % i == 0)
            {
                ans.push_back(i);
                if (i != a / i)
                    ans.push_back(a / i);
            }
        }
        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}