#include <bits/stdc++.h>
using namespace std;

string str1;
vector<int> num1;
int num2;

void merge(string s1)
{
    for (int i = s1.size() - 1; i >= 0; i--)
        num1.push_back(s1[i] - '0');
}

void solve()
{
    int i = 0;
    int cnt = 0;
    for (i = 0; i < num1.size(); i++)
    {
        cnt = cnt + num1[i] * num2;
        num1[i] = cnt % 10;
        cnt = cnt / 10;
    }
    while (cnt)
    {
        num1.push_back(cnt % 10);
        cnt = cnt / 10;
        i++;
    }
}

int main()
{
    cin >> str1;
    cin >> num2;
    merge(str1);
    if (str1 == "0" || num2 == 0)
    {
        cout << 0;
        return 0;
    }
    solve();

    for (int i = num1.size() - 1; i >= 0; i--)
        cout << num1[i];

    return 0;
}