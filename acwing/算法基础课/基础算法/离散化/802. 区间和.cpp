#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;

int n, m;
vector<PII> action;
vector<PII> query; // 存储查询的区间，因为求区间和使用的是前缀和方法，所以查询时只需要求num[r] - num[l-1]的值即可。所以存储(l-1, r).
vector<int> label; // 存储的是离散前的序号，如3映射到0，则label[0] = 3
int cnt[300010];   // 存储元素的值，例如：离散前3号数值为5，且label[0] = 3, 则cnt[0] = 5

int find(int x)
{
    int left = 0;
    int right = label.size() - 1;
    while (left < right)
    {
        int mid = left + right >> 1;
        if (label[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

void add()
{
    for (int i = 0; i < action.size(); i++)
    {
        int pos = find(action[i].first);
        cnt[pos] += action[i].second;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x, c;
        cin >> x >> c;
        label.push_back(x);
        action.push_back({x, c});
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back({l - 1, r});
        label.push_back(l - 1);
        label.push_back(r);
    }

    sort(label.begin(), label.end());
    label.erase(unique(label.begin(), label.end()), label.end());

    add();
    //求前缀和
    for (int i = 1; i < label.size(); i++)
        cnt[i] += cnt[i - 1];
    //查询
    for (int i = 0; i < query.size(); i++)
    {
        int left = find(query[i].first);
        int right = find(query[i].second);
        cout << cnt[right] - cnt[left] << endl;
    }

    return 0;
}