#include <bits/stdc++.h>
using namespace std;

int flag;
string str1, str2;
vector<int> num1, num2;

// 判断两个数大小，以便确定谁减谁
void judge(string s1, string s2)
{
    if (s1.size() > s2.size())
        flag = 1;
    else if (s1.size() < s2.size())
        flag = -1;
    else
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] < s2[i])
            {
                flag = -1;
                return;
            }
            else if (s1[i] > s2[i])
            {
                flag = 1;
                return;
            }
            else
                continue;
        }
    }
}

// 将两个字符串变成数字，s1为被减数，s2为减数
// 相应的，num1为被减数，num2为减数
void merge(string s1, string s2)
{
    for (int i = s1.size() - 1; i >= 0; i--)
        num1.push_back(s1[i] - '0');
    for (int i = s2.size() - 1; i >= 0; i--)
        num2.push_back(s2[i] - '0');
}

void solve()
{
    int i = 0;
    int cnt = 0;
    for (i = 0; i < num2.size(); i++)
    {
        num1[i] = cnt + num1[i] - num2[i];
        if (num1[i] < 0)
        {
            num1[i] += 10;
            cnt = -1;
        }
        else
            cnt = 0;
    }
    while (cnt)
    {
        num1[i] = cnt + num1[i];
        if (num1[i] < 0)
        {
            num1[i] += 10;
            cnt = -1;
        }
        else
            cnt = 0;
        i++;
    }
    // 去掉前导0
    for (int i = num1.size() - 1; i > 0; i--)
    {
        if (num1[i])
            break;
        else
            num1.pop_back();
    }
}

int main()
{
    cin >> str1 >> str2;
    judge(str1, str2);
    if (flag == 1)
        merge(str1, str2);
    else
        merge(str2, str1);
    solve();

    if (flag == -1)
        cout << '-';
    for (int i = num1.size() - 1; i >= 0; i--)
        cout << num1[i];
    return 0;
}