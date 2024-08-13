#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int n;
vector<PII> nums;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        nums.push_back({l, r});
    }
    sort(nums.begin(), nums.end());

    int cnt = 1;
    int left = nums[0].first;
    int right = nums[0].second;
    for (int i = 0; i < n; i++)
    {
        if (nums[i].first > right)
        {
            left = nums[i].first;
            right = nums[i].second;
            cnt++;
        }
        else
        {
            right = max(right, nums[i].second);
        }
    }

    cout << cnt << endl;
    return 0;
}